package MidtermTest;

import java.io.*;
import java.net.*;
import TCP.Laptop;

public class TCP_ObjectStream_fmAsgyM8 {
    public static String fixName(String s){
        String [] words = s.split(" ");
        int n = words.length;
        String tmp = words[0];
        words[0] = words[n - 1];
        words[n - 1] = tmp;
        return String.join(" ", words);
    }
    
    public static int fixQuantity(int n){
        String s = String.valueOf(n);
        StringBuilder sb = new StringBuilder(s);
        String reversed = sb.reverse().toString();
        int res = Integer.parseInt(reversed);
        return res;
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2209;
        String message = "B22DCVT114;fmAsgyM8";
        System.out.println(message);
        
        try(Socket socket = new Socket(host,port)){
            socket.setSoTimeout(5000);
            
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            oos.writeObject(message);
            oos.flush();
            
            Laptop l = (Laptop) ois.readObject();
            System.out.println(l);
            
            //Standardize
            l.setName(fixName(l.getName()));
            l.setQuantity(fixQuantity(l.getQuantity()));
            System.out.println(l);
            
            //Send
            oos.writeObject(l);
            oos.flush();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
