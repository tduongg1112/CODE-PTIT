package UDP;

import java.net.*;
import UDP.Product;
import java.io.*;

public class Object_CaZHjaA6 {
    public static String fixName(String s){
        String [] words = s.trim().split("\\s+");
        int n = words.length;
        String temp = words[0];
        words[0] = words[n - 1];
        words[n - 1] = temp;
        String res = String.join(" ", words);
        return res;
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
        String sCode = "B22DCVT114";
        String qCode = "CaZHjaA6";
        String message = ";" + sCode + ";" + qCode;
        System.out.println(message);
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out  = new DatagramPacket (message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] buffer = new byte[10000];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            // Tách 8 byte RequestID và nhận Object
            String reqId = new String(in.getData(), 0, 8);
            ByteArrayInputStream bais = new ByteArrayInputStream(in.getData(), 8, in.getLength() - 8);
            ObjectInputStream ois = new ObjectInputStream(bais);
            Product p = (Product) ois.readObject(); 
            p.info();
            
            // Standardize
            p.setName(fixName(p.getName()));
            p.setQuantity(fixQuantity(p.getQuantity()));
            
            // Đóng gói và gửi đi
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(p);
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
