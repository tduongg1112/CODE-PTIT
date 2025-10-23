//  Tính tổng các số nguyên trong chuỗi

package TCP;

import java.io.*;
import java.net.*;

public class TCP_ByteStream_MTMrUH8C {
    public static void main(String[] args) throws Exception{
        String host = "203.162.10.109";
        int port = 2206;
        
        String sCode = "B22DCVT114";
        String qCode = "MTMrUH8C";
        String message = sCode + ";" + qCode;
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
//      sử dụng luồng byte dữ liệu (InputStream/OutputStream) để trao đổi thông tin theo thứ tự: 
        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();
        
//a.	Gửi mã sinh viên và mã câu hỏi theo định dạng "studentCode;qCode". Ví dụ: "B16DCCN999;C64967DD"
        os.write(message.getBytes());
        os.flush();
            System.out.println("Sent:" + message);
            
//b.	Nhận dữ liệu từ server là một chuỗi gồm các giá trị nguyên được phân tách với nhau bằng  "|"
//Ex: 2|5|9|11
        byte[] buffer = new byte[1024];
        int read = is.read(buffer);
        String received = new String (buffer, 0 , read).trim();
            System.out.println(received);
            
//c.	Thực hiện tìm giá trị tổng của các số nguyên trong chuỗi và gửi lên server
        String [] all = received.split("\\|");
        int sum = 0;
        for (String x : all){
            sum += Integer.parseInt(x);
        }
            System.out.println(sum);
        
        os.write(String.valueOf(sum).getBytes());
        os.flush();
            System.out.println("Sent to server:" + sum);

//d.	Đóng kết nối và kết thúc  
        socket.close();

        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
