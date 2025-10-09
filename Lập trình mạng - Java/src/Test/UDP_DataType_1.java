package Test;

import java.io.*;
import java.net.*;
import java.util.*;

public class UDP_DataType_1 {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String message = ";B22DCVT114;Nlu2Nuyi";
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
            String [] numparts = parts[1].split(",");
            int [] nums = new int[numparts.length];
//            int min = Integer.MAX_VALUE;
//            int max = Integer.MIN_VALUE;
            
//            for (int i = 0; i < nums.length; i++){
//                nums[i] = Integer.parseInt(numparts[i]);
//                if (nums[i] < min){
//                    min = nums[i];
//                }
//                if (nums[i] > max){
//                    max = nums[i];
//                }
//            }
//            System.out.println("MAX: " + max + "\n" + "MIN: " + min);

            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < nums.length; i++){
                nums[i] = Integer.parseInt(numparts[i]);
                arr.add(i, nums[i]);
            }
            Collections.sort(arr);
            int min = arr.get(0);
            int max = arr.get(arr.size() - 1);
            
            String res = reqId + ";" + max + "," + min;
            System.out.println(res);
            DatagramPacket dp = new DatagramPacket(res.getBytes(), res.length(), server, port);
            client.send(dp);
            
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
