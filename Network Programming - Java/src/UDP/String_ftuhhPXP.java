//  Chuẩn hóa viết hoa chữ cái đầu mỗi từ

package UDP;

import java.net.*;

public class String_ftuhhPXP {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        String sCode = "B22DCVT114";
        String qCode = "ftuhhPXP";
        String message = ";" + sCode + ";" + qCode;
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] data = new byte[4096];
            DatagramPacket in = new DatagramPacket (data, data.length);
            client.receive(in);
            String response = new String(in.getData(), 0, in.getLength());
            
            String [] parts = response.split(";");
            String reqId = parts[0];     
            String [] words = parts[1].split(" ");
            StringBuilder sb = new StringBuilder();
            for (String x : words){
                sb.append(Character.toUpperCase(x.charAt(0)));
                sb.append(x.substring(1).toLowerCase());
                sb.append(" ");
            }
            String res = reqId + ";" + sb.toString().trim();
            System.out.println("Result: " + res);
            
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
