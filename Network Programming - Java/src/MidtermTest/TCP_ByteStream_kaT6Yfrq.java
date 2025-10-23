//  Sinh dãy Collatz và đếm độ dài

package MidtermTest;

import java.io.*;
import java.net.*;

public class TCP_ByteStream_kaT6Yfrq {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2206;
        String message = "B22DCVT114;kaT6Yfrq";
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            os.write(message.getBytes());
            os.flush();
            
            byte [] buffer = new byte[4096];
            int bytesRead = is.read(buffer);
            String response = new String (buffer, 0, bytesRead);
            System.out.println("Received : "  + response);
            
//  Nhận dữ liệu từ server là một số nguyên n nhỏ hơn 400. Ví dụ: 7
//  Thực hiện các bước sau đây để sinh ra chuỗi từ số nguyên n ban đầu và gửi lên server.
//        Bắt đầu với số nguyên nn:
//            Nếu n là số chẵn, chia nn cho 2 để tạo ra số tiếp theo trong dãy.
//            Nếu n là số lẻ và khác 1, thực hiện phép toán n=3*n+1 để tạo ra số tiếp theo.
//        Lặp lại quá trình trên cho đến khi n = 1, tại đó dừng thuật toán.
//  Kết quả là một dãy số liên tiếp, bắt đầu từ n ban đầu, kết thúc tại 1 và độ dài của chuỗi theo format "chuỗi kết quả; độ dài"  Ví dụ: kết quả với n = 7 thì dãy: 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1; 17;  
            
            int n = Integer.parseInt(response);
            int first = n;
            int cnt = 1;
            StringBuilder sb = new StringBuilder();
            sb.append(first).append(" ");
            while (n != 1){
                if (n % 2 == 0){
                    n /= 2;
                } else {
                    n = 3 * n + 1;
                }
                sb.append(n);
                sb.append(" ");
                cnt++;
            }
            
            String res = sb.toString().trim() + "; " + cnt;
            System.out.println("RESULT: " + res);
            os.write(res.getBytes());
            os.flush();
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
