//  Chuyển đổi số sang hệ Octa và Hexa

package TCP;

import java.io.*;
import java.net.*;

public class TCP_DataStream_9PVTjwJW {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        
        String sCode = "B22DCVT114";
        String qCode = "9PVTjwJW";
        String message = sCode + ";" + qCode;
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
        DataInputStream dis = new DataInputStream(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        
        // a. Gửi mã sinh viên và mã câu hỏi theo định dạng "studentCode;qCode".
        dos.writeUTF(message);
        dos.flush();
            System.out.println(message);
        
        // b. Nhận một số nguyên hệ thập phân từ server. Ví dụ: 255
        // c. Chuyển đổi số nguyên nhận được sang hai hệ cơ số 8 và 16. Gửi lần lượt chuỗi kết quả lên server.
        int response = dis.readInt();
        
        String octal = Integer.toOctalString(response);
        String hexa = Integer.toHexString(response).toUpperCase();
            System.out.println("Octal:" + octal);
            System.out.println("Hexa:" + hexa);
        
        dos.writeUTF(octal);
        dos.writeUTF(hexa);
        dos.flush();
        
        socket.close();
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
