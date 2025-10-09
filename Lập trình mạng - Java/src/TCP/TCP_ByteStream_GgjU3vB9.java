package TCP;

import java.io.*;
import java.net.*;

public class TCP_ByteStream_GgjU3vB9 {
    public static boolean CheckPrime(int n){
        if (n < 2) return false;
        for (int i = 2; i <= Math.sqrt(n); i++){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2206;
        
        String sCode = "B22DCVT114";
        String qCode = "GgjU3vB9";
        String message = sCode + ";" + qCode;
        System.out.println(message);
        
        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();
        
        os.write(message.getBytes());
        os.flush();
        
        byte [] buffer = new byte[1024];
        int x = is.read(buffer);
        String response = new String (buffer, 0, x);
            System.out.println(response);
        
        String [] res = response.split("\\,");
        int sum = 0;
        int [] num = new int [res.length];
        for (int i = 0; i < res.length; i++){
            num[i] = Integer.parseInt(res[i]);
            if (CheckPrime(num[i])){
                sum += num[i];
            }
        }
            System.out.println("SUM" + sum);
        
        String requestB = sum + "";
        os.write(requestB.getBytes());
        os.flush();
        
        is.close();
        os.close();
        socket.close();
        
        } catch(IOException e){
            e.printStackTrace();
        }
    }
}
