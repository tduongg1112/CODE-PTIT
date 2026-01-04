package FinalTest;

import java.io.*;
import java.net.*;

public class TCP_ByteStream_RwTTSKN4 {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2206;
        String message = "B22DCCN441;RwTTSKN4";
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            os.write(message.getBytes());
            os.flush();
            
            byte [] data = new byte[4096];
            int bytesread = is.read(data);
            
            String receive = new String(data, 0, bytesread);
            System.out.println("Received: " + receive);
            
            String [] parts = receive.split(",");
            
            int [] nums = new int[parts.length];
            for (int i = 0; i < nums.length; i++){
                nums[i] = Integer.parseInt(parts[i]);
            }
            
            int current = 0;
            int currentLength = 1;
            int best = 0;
            int bestLength = 1;
            
            for (int i = 1; i < nums.length; i++){
                if (nums[i] > nums[i - 1]){
                    currentLength++;
                }
                else {
                    current = i;
                    currentLength = 1;
                }
                if (currentLength > bestLength){
                    bestLength = currentLength;
                    best = current;
                }
            }
            
            StringBuilder sb = new StringBuilder();
            for (int i = best; i < best + bestLength; i++){
                sb.append(nums[i]).append(",");
            }
            sb.deleteCharAt(sb.length() - 1);
            sb.append(";").append(bestLength);
            String res = sb.toString();
            System.out.println("Result: " + res);
            
            os.write(res.getBytes());
            os.flush();
            
        } catch (Exception e) {
        }
    }
}
