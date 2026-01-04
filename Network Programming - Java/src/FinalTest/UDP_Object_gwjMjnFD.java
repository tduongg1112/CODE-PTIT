package FinalTest;

import UDP.Book;
import java.io.*;
import java.net.*;

public class UDP_Object_gwjMjnFD {
    public static String fixTitle (String s){
        String [] words = s.trim().toLowerCase().split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static String fixAuthor (String s){
        StringBuilder sb = new StringBuilder();
        String [] words = s.trim().toLowerCase().split(" ");
        int n = words.length;
        sb.append(words[0].toUpperCase());
        sb.append(", ");
        for (int i = 1; i < words.length; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static String fixIsbn (String s){
        return String.format("%s-%s-%s-%s-%s", s.substring(0,3), s.substring(3,4), s.substring(4,6), s.substring(6,12), s.substring(12));
    }
    
    public static String fixDate (String s){
        String [] parts = s.split("-");
        StringBuilder sb = new StringBuilder();
        String yy = parts[0];
        String mm = parts[1];
        String dd = parts[2];
        sb.append(mm).append("/").append(yy);
        return sb.toString();
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2209;
        String message  = ";B22DCVT036;gwjMjnFD";
        
        try (DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte [] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            String reqId = new String(in.getData(), 0, 8);
            ByteArrayInputStream bais = new ByteArrayInputStream(in.getData(), 8, in.getLength() - 8);
            ObjectInputStream ois = new ObjectInputStream(bais);
            Book b = (Book) ois.readObject();
            
            b.setTitle(fixTitle(b.getTitle()));
            b.setAuthor(fixAuthor(b.getAuthor()));
            b.setIsbn(fixIsbn(b.getIsbn()));
            b.setPublishDate(fixDate(b.getPublishDate()));
            
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(b);
            oos.flush();
            
            byte [] sendData = new byte[baos.size() + 8];
            System.arraycopy(reqId.getBytes(), 0, sendData, 0, 8);
            System.arraycopy(baos.toByteArray(), 0, sendData, 8, baos.size());
            DatagramPacket dp = new DatagramPacket(sendData, sendData.length, server, port);
            client.send(dp);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
