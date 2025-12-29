// Chuyển đổi thập phân -> nhị phân

package FinalTest;

import java.io.*;
import java.net.*;

public class TCP_DataStream_Xqm8r62f {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String message = "B22DCVT114;Xqm8r62f";
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            out.writeUTF(message);
            out.flush();
            
            int num = in.readInt();
            System.out.println("Received: " + num);
            
            String convert = Integer.toBinaryString(num);
            System.out.println("Binary: " + convert);
            
            out.writeUTF(convert);
            out.flush();
        } catch (Exception e){    
        }
    }
}
