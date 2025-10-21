package MidtermTest;

import java.net.*;

public class UDP_String_VNNgqFpq {
    public static String ChuanHoa(String s){
        String [] words = s.trim().toLowerCase().split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port =  2208;
        String message = ";B22DCVT114;VNNgqFpq";
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            String response = new String (in.getData(), 0, in.getLength());
            
            String [] parts = response.split(";");
            String reqId = parts[0];
            String words = parts[1];
            
            String res = reqId + ";" + ChuanHoa(words);
            System.out.println("RESULT: " + res);
            
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        } catch (Exception e) {
        }
    }
}
