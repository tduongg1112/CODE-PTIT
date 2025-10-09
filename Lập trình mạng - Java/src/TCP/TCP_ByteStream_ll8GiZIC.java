package TCP;

import java.io.*;
import java.net.*;

public class TCP_ByteStream_ll8GiZIC {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2206;
        
        String sCode = "B22DCVT114";
        String qCode = "ll8GiZIC";
        String message = sCode + ";" + qCode;
        System.out.println(message);
        
        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();

//a. Gửi mã sinh viên và mã câu hỏi theo định dạng "studentCode;qCode".
        os.write(message.getBytes());
        os.flush();
            System.out.println(message);
           
//b. Nhận dữ liệu từ server là một chuỗi các số nguyên được phân tách bởi ký tự ",".
//Ví dụ: " 3,7,2,5,8,1"
        byte [] buffer = new byte [1024];
        int readByte = is.read(buffer);
        String response = new String (buffer, 0, readByte).trim();
            System.out.println("RESPONSE " + response);
        
        String [] num = response.split("\\,");
        
        int n = num.length;
        int [] res = new int[n];
        
        int index = -1, diff = Integer.MAX_VALUE, left = 0, right = 0;
        int bestLeft = 0, bestRight = 0;
        for (int i = 0; i < n; i++){
            res[i] = Integer.parseInt(num[i]);
            right += res[i];
        }
        right -= res[0];
        for (int i = 1; i < n - 1; i++){
            left += res[i - 1];
            right -= res[i];
            if (Math.abs(left - right) < diff){
                index = i;
                diff  = Math.abs(left - right);
                bestLeft = left;
                bestRight = right;
            }
        }
        
        String result = index + "," + bestLeft + "," + bestRight + "," + diff ;
        os.write(result.getBytes());
        os.flush();
            System.out.println("RESULT " + result);
        
//c. Tìm vị trí mà độ lệch của tổng bên trái và tổng bên phải là nhỏ nhất -> Gửi lên server vị trí đó, tổng trái, tổng phải và độ lệch. Ví dụ: với dãy " 3,7,2,5,8,1", vị trí 3 có độ lệch nhỏ nhất = 3 → Kết quả gửi server: "3,12,9,3"
//d. Đóng kết nối và kết thúc chương trình.            
        
        is.close();
        os.close();
        socket.close();
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
