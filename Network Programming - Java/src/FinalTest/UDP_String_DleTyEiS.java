package FinalTest;

import java.io.*;
import java.net.*;

public class UDP_String_DleTyEiS {
    public static String remove (String s1, String s2){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s1.length(); i++){
            char c = s1.charAt(i);
            if (s2.indexOf(c) == -1){
                sb.append(c);
            }
        }
        return sb.toString();
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String message = ";B22DCCN441;DleTyEiS";
        
        try (DatagramSocket client = new DatagramSocket()) {
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            String receive = new String(in.getData());
            String [] parts = receive.split(";");
            String reqId = parts[0];
            String s1 = parts[1];
            String s2 = parts[2];
            
            String output = remove(s1, s2);
            String res = reqId + ";" + output;
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        } catch (Exception e) {
        }
    }
}
