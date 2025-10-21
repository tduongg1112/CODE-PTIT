package UDP;

import java.io.*;
import java.net.*;

public class Object_xJ8bqEu1 {
    public static String fixName (String s){
        String [] words = s.toLowerCase().split("\\s+");
        StringBuilder sb = new StringBuilder();
        int n = words.length;
        sb.append(words[n - 1].toUpperCase()).append(", ");
        for (int i = 0; i < n - 1; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static String tknh (String s){
        String [] words = s.toLowerCase().split("\\s+");
        StringBuilder sb = new StringBuilder();
        int n = words.length;
        for (int i = 0; i < n - 1; i++){
            sb.append(words[i].charAt(0));
        }
        sb.append(words[n - 1]);
        return  sb.toString().trim();
    }
    
    public static String fixDob (String s){
        String [] parts = s.split("-");
        String m = parts[0], d = parts[1], y = parts[2];
        String res = d + "/" + m + "/" + y;
        return res;
    } 
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2209;
        String message = ";B22DCVT114;xJ8bqEu1";
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket ()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] buffer = new byte[1024];
            DatagramPacket in = new DatagramPacket (buffer, buffer.length);
            client.receive(in);
            
            String reqId = new String(in.getData(), 0, 8);
            ByteArrayInputStream bais = new ByteArrayInputStream(in.getData(), 8, in.getLength() - 8);
            ObjectInputStream ois = new ObjectInputStream(bais);
            Customer c = (Customer) ois.readObject();
            System.out.println("Data: " + c);
            
            c.setUserName(tknh(c.getName()));
            c.setName(fixName(c.getName()));
            c.setDayOfBirth(fixDob(c.getDayOfBirth()));
            System.out.println("Result: " + c);
            
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(c);
            oos.flush();
            byte [] sendData = new byte[8 + baos.size()];
            System.arraycopy(reqId.getBytes(), 0, sendData, 0, 8);
            System.arraycopy(baos.toByteArray(), 0, sendData, 8, baos.size());
            DatagramPacket dp = new DatagramPacket (sendData, sendData.length, server, port);
            client.send(dp);
            
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}
