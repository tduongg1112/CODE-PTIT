//  Đếm ký tự và chữ số xuất hiện nhiều hơn 1 lần

package MidtermTest;

import java.net.*;
import java.io.*;
import java.util.*;

public class TCP_CharacterStream_XVriIXzA {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String message = "B22DCVT114;XVriIXzA";
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)) {
            socket.setSoTimeout(5000);
            
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            out.write(message);
            out.newLine();
            out.flush();
            
            String response = in.readLine();
            System.out.println("Received: " + response);
            
            Map<Character, Integer> map = new LinkedHashMap<>();
            for (char c : response.toCharArray()){
                if (Character.isLetterOrDigit(c)){ // dem chu va so
                    map.put(c, map.getOrDefault(c, 0) + 1);
                }
            }
            
            StringBuilder sb = new StringBuilder();
            for (Map.Entry<Character, Integer> entry : map.entrySet()){
                if (entry.getValue() > 1){
                    sb.append(entry.getKey()).append(":");
                    sb.append(entry.getValue()).append(",");
                }
            }
            String res = sb.toString();
            System.out.println("RESULT: " + res);
            out.write(res);
            out.newLine();
            out.flush();
                    
        } catch (Exception e) {
        }
    }
}
