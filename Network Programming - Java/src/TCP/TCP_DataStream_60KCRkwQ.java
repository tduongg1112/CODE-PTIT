//  Tổng, tích của Big Integer

package TCP;

import java.io.*;
import java.net.*;

public class TCP_DataStream_60KCRkwQ {
    public static void main (String [] Arg) throws Exception{
        String host = "203.162.10.109";
        int port = 2207;
        
        String sCode = "B22DCVT114";
        String qCode = "60KCRkwQ";
        String message = sCode + ";" + qCode;
        
        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
//Sử dụng luồng byte dữ liệu (DataInputStream/DataOutputStream) để trao đổi thông tin theo thứ tự: 
        DataInputStream dis = new DataInputStream(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        
//a.	Gửi chuỗi là mã sinh viên và mã câu hỏi theo định dạng "studentCode;qCode". Ví dụ: "B15DCCN999;1D25ED92"
        dos.writeUTF(message);
        dos.flush();
        
//b.	Nhận lần lượt hai số nguyên a và b từ server
        int a = dis.readInt();
        int b = dis.readInt();
        System.out.println("A & B: " + a + ", " + b);
        
//c.	Thực hiện tính toán tổng, tích và gửi lần lượt từng giá trị theo đúng thứ tự trên lên server
        int sum = a + b;
        int product  = a * b;
        dos.writeInt(sum);
        dos.writeInt(product);
        dos.flush();
        System.out.println("SUM & PRODUCT:" + sum + ", " + product);
        
//d.	Đóng kết nối và kết thúc
        
        } catch (IOException e) {
        }
    }
}
