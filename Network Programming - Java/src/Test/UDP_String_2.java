//  Từ điển ngược

package Test;

import java.net.*;
import java.util.*;

public class UDP_String_2 {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String message = ";B22DCVT114;KiWvIVYw";
        System.out.println(message);
        
        try(DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            String response = new String(in.getData(), 0, in.getLength());
            String [] parts = response.split(";");
            String reqId = parts[0];
            String [] words = parts[1].trim().split(" ");
            
            Arrays.sort(words, (a,b) -> b.compareToIgnoreCase(a));
            
            String tmp = String.join(",", words);
            String res = reqId + ";" + tmp;
            System.out.println(res);
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        }catch(Exception e){
            
        }
    }
}
