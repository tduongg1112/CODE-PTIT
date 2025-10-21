package Test;

import java.net.*;
import java.io.*;
import java.util.*;

public class UDP_Datatype_2 {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String message = ";B22DCVT114;DKQ4XgGd";
        System.out.println(message);
        
        try(DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            String response  = new String(in.getData(), 0, in.getLength());
            String [] parts =   response.split(";");
            String reqId = parts[0];
            String [] numparts = parts[1].split(",");
            int [] nums = new int[numparts.length];
            ArrayList <Integer> list = new ArrayList();
            
            for (int i = 0; i < nums.length; i++){
                nums[i] = Integer.parseInt(numparts[i]);
                list.add(nums[i]);
            }
            Collections.sort(list);
            int secondMin = list.get(1);
            int secondMax = list.get(list.size() - 2);
            
            String res = reqId + ";" + secondMax + "," + secondMin;
            DatagramPacket dp = new DatagramPacket(res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        }catch (Exception e){
            
        }
    }
}
