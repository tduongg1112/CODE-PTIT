//  Tìm Max trong cửa sổ trượt kích thước = k

package MidtermTest;

import java.io.*;
import java.net.*;
import java.util.*;

public class UDP_DataType_uXppE33I {
    public static int [] slidingWindow (int [] arr, int k){
        int n = arr.length;
        int [] res = new int[n - k + 1];
        
        Deque<Integer> dq = new LinkedList<>();
        
        int out = 0;
        for (int i = 0; i < n; i++){
            while (!dq.isEmpty() && dq.peekFirst() <= i - k) {
                dq.pollFirst();
            }
            while (!dq.isEmpty() && arr[dq.peekLast()] < arr[i]) {
                dq.pollLast();
            }
            dq.offerLast(i);
            if (i >= k - 1) {
                res[out++] = arr[dq.peekFirst()];
            }
        }
        return res;
        
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2007;
        String message = ";B22DCVT114;uXppE33I";
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out  = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] data = new byte[4096];
            DatagramPacket in = new DatagramPacket(data, data.length);
            client.receive(in);
            
            String response = new String (in.getData(), 0, in.getLength());
            String [] parts = response.split(";");
            String redId = parts[0];
            int n = Integer.parseInt(parts[1]);
            int k = Integer.parseInt(parts[2]);
            String [] tmp = parts[3].split(",");
            List<Integer> arr = new ArrayList<>();
            
            
            
            
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
