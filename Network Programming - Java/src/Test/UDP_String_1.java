//  Viết hoa chữ cái đầu mỗi từ

package Test;

import java.net.*;

public class UDP_String_1 {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String message = ";B22DCVT114;ftuhhPXP";
        System.out.println(message);
        
        try(DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket (message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            String response = new String(in.getData(), 0, in .getLength());
            String [] parts = response.split(";");
            String reqId = parts[0];
            String [] words = parts[1].split(" ");
            for (int i = 0; i < words.length; i++){
                words[i] = Character.toUpperCase(words[i].charAt(0)) + words[i].substring(1).toLowerCase();
            }
            String res = String.join(" ", words);
            String ans = reqId + ";" + res.trim();
            System.out.println(ans);
            
            DatagramPacket dp = new DatagramPacket(ans.getBytes(), ans.length(), server, port);
            client.send(dp);
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
