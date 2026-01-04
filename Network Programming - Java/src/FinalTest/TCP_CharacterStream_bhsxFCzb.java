// Tìm kiếm tên miền

package FinalTest;

import java.io.*;
import java.net.*;

public class TCP_CharacterStream_bhsxFCzb {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String message = "B22DCVT036;bhsxFCzb";
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            bw.write(message);
            bw.newLine();
            bw.flush();
            
            String receive = br.readLine();
            String [] emails = receive.split(",");
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < emails.length; i++){
                if (emails[i].endsWith(".edu")){
                    sb.append(emails[i].trim()).append(", ");
                }
            }
            sb.deleteCharAt(sb.length() - 2).deleteCharAt(sb.length() - 1);
            String res = sb.toString();
            System.out.println(res);
            
            bw.write(res);
            bw.newLine();
            bw.flush();
            
        } catch (Exception e) {
        }
    }
}
