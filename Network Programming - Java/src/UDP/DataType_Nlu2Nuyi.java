//  Max, Min

package UDP;

import java.net.*;

public class DataType_Nlu2Nuyi {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2207;
        String sCode = "B22DCVT114";
        String qCode = "Nlu2Nuyi";
        String message = ";" + sCode + ";" + qCode;
        System.out.println(message);
        
        try(DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] data = new byte[4096];
            DatagramPacket in = new DatagramPacket(data, data.length);
            client.receive(in);
            
            String response = new String(in.getData(), 0, in.getLength());
            String [] parts = response.split(";");
            String reqId = parts[0];
            String numParts [] = parts[1].split(",");
            
            int [] nums = new int [numParts.length]; 
            for (int i = 0; i < nums.length - 1; i++){
                nums[i] = Integer.parseInt(numParts[i]);
            }
            
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            for (int x : nums){
                if (x < min) min = x;
                if (x > max) max = x;
            }
            
            String res = reqId + ";" + max + "," + min;
            System.out.println("RES: " + res);
            DatagramPacket dp = new DatagramPacket(res.getBytes(), res.length(), server, port);
            client.send(dp);
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
