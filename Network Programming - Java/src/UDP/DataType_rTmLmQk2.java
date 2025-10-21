package UDP;

import java.math.BigInteger;
import java.net.*;

public class DataType_rTmLmQk2 {
    public static void main(String[] args){
        String host = "203.162.10.109";
        int port = 2207;
        String sCode = "B22DCVT114";
        String qCode = "rTmLmQk2";
        String message = ";" + sCode + ";" + qCode;
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] data = new byte[4096];
            DatagramPacket in = new DatagramPacket(data, data.length);
            client.receive(in);
            String response = new String (in.getData(), 0, in.getLength());
            System.out.println("Server Response: " + response);
            
            String[] parts = response.split(";");
            String reqId = parts[0];
            BigInteger a = new BigInteger(parts[1]);
            BigInteger b = new BigInteger(parts[2]);
            BigInteger sum = a.add(b);
            BigInteger diff = a.subtract(b);
            String res = reqId + ";" + sum + "," + diff;
            System.out.println("Result: " + res);
            
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        }catch(Exception e){}
    }
}
