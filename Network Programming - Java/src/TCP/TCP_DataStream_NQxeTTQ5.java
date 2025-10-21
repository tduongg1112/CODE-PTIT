package TCP;

import java.io.*;
import java.net.*;

public class TCP_DataStream_NQxeTTQ5 {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String sCode = "B22DCVT114";
        String qCode = "NQxeTTQ5";
        String message = sCode + ";" + qCode;
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            
            out.writeUTF(message);
            out.flush();

//b. Nhận chuỗi chứa mảng số nguyên từ server, các phần tử được phân tách bởi dấu phẩy ",". Ví dụ: "1,3,2,5,4,7,6"
//c. Tính số lần đổi chiều và tổng độ biến thiên trong dãy số.
//-  Đổi chiều: Khi dãy chuyển từ tăng sang giảm hoặc từ giảm sang tăng 
//-  Độ biến thiên: Tổng giá trị tuyệt đối của các hiệu số liên tiếp 

        String response = in.readUTF();
            System.out.println("RES: " + response);
        String [] words = response.split("\\,");
        int n = words.length;
        int [] list = new int[n];
        for (int i = 0; i < n; i++){
            list[i] = Integer.parseInt(words[i].trim());
        }
        
        int bienthien = 0;
        int doichieu = 0;
        
        for (int i = 1; i < list.length; i++) {
        bienthien += Math.abs(list[i] - list[i - 1]);
        if (i >= 2) {
            int diff1 = list[i] - list[i - 1];
            int diff2 = list[i - 1] - list[i - 2];
            if ((diff1 > 0 && diff2 < 0) || (diff1 < 0 && diff2 > 0)) {
                doichieu++;
            }
        }
}
        
        
//        int prevsign = 0;
//        for (int i = 1; i < list.length; i++){
//            int diff = list[i] - list[i - 1];
//            if (diff == 0) continue;
//            int sign = (diff > 0) ? 1 : -1;
//            if (prevsign == 0){
//                prevsign = sign;
//            }
//            else if (prevsign != sign){
//                doichieu++;
//                prevsign = sign;
//            }
//        }
            
        out.writeInt(doichieu);
        out.writeInt(bienthien);
        out.flush();
            System.out.println(doichieu + ";" + bienthien);

        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
