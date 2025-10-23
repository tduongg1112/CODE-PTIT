//  SecondMax, SecondMin

package UDP;

import java.net.*;
import java.util.*;

public class DataType_DKQ4XgGd {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String sCode = "B22DCVT114";
        String qCode = "DKQ4XgGd";
        String message = ";" + sCode + ";" + qCode;
        System.out.println(message);
        
        try(DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            //  Receiver data form server
            byte [] data = new byte[4096];
            DatagramPacket in = new DatagramPacket(data, data.length);
            client.receive(in);
            String response = new String(in.getData(), 0, in.getLength());
            System.out.println("response: " + response);
            
            //  Xu ly
            String [] parts = response.split(";");
            String reqId = parts[0];
            String [] numParts = parts[1].split(",");
            
            ArrayList <Integer> arr = new ArrayList<>();
            int [] nums = new int[numParts.length];
            for (int i = 0; i < nums.length; i++){
                nums[i] = Integer.parseInt(numParts[i]);
                arr.add(i, nums[i]);
            }
            Collections.sort(arr);
            int secondMin = arr.get(1);
            int secondMax = arr.get(arr.size() - 2);
            
            
            String res = reqId + ";" + secondMax + "," + secondMin;
            DatagramPacket dp = new DatagramPacket(res.getBytes(), res.length(), server, port);
            client.send(dp);
            System.out.println(res);
            
        }catch(Exception e){
            
        }
    }
}
