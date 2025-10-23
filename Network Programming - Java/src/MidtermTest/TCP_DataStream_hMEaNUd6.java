//  Decode Ceasar Cipher

package MidtermTest;

import java.io.*;
import java.net.*;

public class TCP_DataStream_hMEaNUd6 {
    public static String decodeCeasar(String s, int n){
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()){
            if (Character.isUpperCase(c)){
                sb.append((char) ((c - 'A' - n + 26) % 26 + 'A'));
            } else if (Character.isLowerCase(c)){
                sb.append((char) ((c - 'a' - n + 26) % 26 + 'a'));
            } else sb.append(c);
        }
        return sb.toString();
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String message = "B22DCVT114;hMEaNUd6";
        System.out.println(message);
        
        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            out.writeUTF(message);
            out.flush();
            
            String response = in.readUTF();
            int num = in.readInt();
            System.out.println("Received: " + response);
            
            String res = decodeCeasar(response, num);
            System.out.println("Result: " + res);
            out.writeUTF(res);
            out.flush();
            
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
