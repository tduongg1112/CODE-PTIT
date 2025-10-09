package TCP;

import java.io.*;
import java.net.*;

public class TCP_ByteStream_o1Tukrnn {
    public static void main(String[] args) throws Exception{
        String host = "203.162.10.109";
        int port = 2206;
        
        String sCode = "B22DCVT114";
        String qCode = "o1Tukrnn";
        String message = sCode + ";" + qCode;
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
//sử dụng luồng byte dữ liệu (InputStream/OutputStream)
       InputStream is = socket.getInputStream();
       OutputStream os = socket.getOutputStream();

//a. Gửi mã sinh viên và mã câu hỏi theo định dạng "studentCode;qCode".
        os.write(message.getBytes());
        os.flush();
            System.out.println("Sent message" + message);    

//b. Nhận dữ liệu từ server là một chuỗi các số nguyên được phân tách bởi ký tự ",".
//Ví dụ: "10,5,15,20,25,30,35"
        byte [] buffer = new byte[1024];
        int yasuo = is.read(buffer);
        String received = new String (buffer, 0, yasuo).trim();
            System.out.println(received);
        
        String [] parts = received.split(",");
        int [] nums = new int[parts.length];
        for (int i = 0; i < parts.length; i++){
            nums[i] = Integer.parseInt(parts[i].trim());
        }

//c. Xác định hai số trong dãy có tổng gần nhất với gấp đôi giá trị trung bình của toàn bộ dãy. Gửi thông điệp lên server theo định dạng "num1,num2" (với num1 < num2)
//Ví dụ: Với dãy "10,5,15,20,25,30,35", gấp đôi giá trị trung bình là 40, hai số có tổng gần nhất là 15 và 25. Gửi lên server chuỗi "15,25".
        double avg = 0;
        for (int n : nums) avg += n;
        avg /= nums.length;
        double target = 2 * avg;

        int num1 = 0, num2 = 0;
        double bestDiff = Double.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int sum = nums[i] + nums[j];
                double diff = Math.abs(sum - target);
                if (diff < bestDiff) {
                    bestDiff = diff;
                    num1 = Math.min(nums[i], nums[j]);
                    num2 = Math.max(nums[i], nums[j]);
                }
            }
        }

        String result = num1 + "," + num2;
        System.out.println("Result: " + result);

        // gửi kết quả lên server
        os.write(result.getBytes());
        os.flush();
        System.out.println("Sent to server: " + result);

//d. Đóng kết nối và kết thúc chương trình.  
        socket.close();
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
