package FinalTest;

import TCP.Customer;
import java.io.*;
import java.net.*;

public class TCP_ObjectStream_YI8bT8EN {
    public static String fixUsername (String s){
        String [] words = s.trim().toLowerCase().split("\\s+");
        int n = words.length;
        StringBuilder sb = new StringBuilder();
        String last = words[n - 1];
        for (int i = 0; i < words.length - 1; i++){
            sb.append(words[i].charAt(0));
        }
        sb.append(last);
        return sb.toString().toLowerCase();
    }
    
    public static String fixName (String s){
        String [] words = s.trim().toLowerCase().split("\\s+");
        int n = words.length;
        StringBuilder sb = new StringBuilder();
        sb.append(words[n - 1].toUpperCase()).append(", ");
        for (int i = 0; i < n - 1; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static String fixDob (String s){
        String [] parts = s.split("-");
        String mm = parts[0];
        String dd = parts[1];
        String yy = parts[2];
        String res = dd + "/" + mm + "/" + yy;
        return res;
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2209;
        String message = "B22DCVT114;YI8bT8EN";
        System.out.println(message);
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());            
            oos.writeObject(message);
            oos.flush();
            
            Customer c = (Customer) ois.readObject();
            System.out.println(c);
            
            c.setUserName(fixUsername(c.getName()));
            c.setName(fixName(c.getName()));
            c.setDayOfBirth(fixDob(c.getDayOfBirth()));
            System.out.println(c);
            
            oos.writeObject(c);
            oos.flush();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
