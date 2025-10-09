package UDP;

import java.net.*;
import java.util.Arrays;

public class String_KiWvIVYw {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String sCode = "B22DCVT114";
        String qCode = "KiWvIVYw";
        String message = ";" + sCode + ";" + qCode;
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] data = new byte[4096];
            DatagramPacket in = new DatagramPacket(data, data.length);
            client.receive(in);
            String response = new String(in.getData(), 0, in.getLength());
            String [] parts = response.split(";");
            String reqId = parts[0];
            
            String [] words = parts[1].split(" ");
            Arrays.sort(words, (a,b) -> b.compareToIgnoreCase(a));
            String ans = String.join(",", words);
            String res = reqId + ";" + ans;
            System.out.println("Result: " + res);
            
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
