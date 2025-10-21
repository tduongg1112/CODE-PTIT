package TCP;

import java.io.*;
import java.net.*;
import java.util.*;

public class TCP_CharacterStream_5jD3PFGB_2 {
    public static void main(String[] args){
        String host = "203.162.10.109";
        int port = 2208;
        
        String sCode = "B22DCVT114";
        String qCode = "o1Tukrnn";
        String message = sCode + ";" + qCode;
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
//      Nhap/Xuat(BufferedReader/BufferedWriter)
        BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

//a. Gửi một chuỗi chứa mã sinh viên và mã câu hỏi với định dạng "studentCode;qCode". Ví dụ: "B15DCCN999;C1234567"
        bw.write(message);
        bw.newLine();
        bw.flush();
            System.out.println("Sent" + message);
            
//b. Nhận từ server một chuỗi chứa nhiều từ, các từ được phân tách bởi khoảng trắng. Ví dụ: "hello world this is a test example"
        String received = br.readLine();
        String [] words = received.split("\\s+");
        
//c. Sắp xếp các từ trong chuỗi theo độ dài, thứ tự xuất hiện. Gửi danh sách các từ theo từng nhóm về server theo định dạng: "a, is, this, test, hello, world, example".
        Arrays.sort(words, Comparator.comparingInt(String :: length));
        String res = String.join(", ", words);
            System.out.println("RESULT" + res);
        bw.write(res);
        bw.newLine();
        bw.flush();

//d. Đóng kết nối và kết thúc chương trình.
        bw.close();
        br.close();
        socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.exit(0); // ép chương trình thoát OK
        }
    }
}
