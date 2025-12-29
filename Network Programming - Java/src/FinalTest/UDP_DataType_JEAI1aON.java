package FinalTest;

import java.net.*;
import java.io.*;
import java.math.BigInteger;

public class UDP_DataType_JEAI1aON {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String message = ";B22DCVT114;JEAI1aON";
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] data = new byte[4096];
            DatagramPacket in = new DatagramPacket(data, data.length);
            client.receive(in);
            String response = new String (in.getData(), 0, in.getLength());
            System.out.println("Received; " + response);
            
            String [] parts = response.split(";");
            String reqId = parts[0];
            String num = parts[1];
            
            int sum = 0;
            for (int i = 0; i < num.length(); i++){
                char c = num.charAt(i);
                if (Character.isDigit(c)){
                    sum += (c - '0');
                }
            }
            
            String res = reqId + ";" + sum;
            DatagramPacket dp = new DatagramPacket (res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        } catch (Exception e) {
        }
    }
}
