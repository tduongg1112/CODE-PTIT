package UDP;

import UDP.Student;
import java.io.*;
import java.net.*;
import java.util.Arrays;

public class Object_YTqTw4Q7 {
    public static String fixName (String name){
        String [] words = name.toLowerCase().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static String fixEmail(String name){
        String [] words = name.split("\\s+");
        StringBuilder sb = new StringBuilder();
        int n = words.length;
        sb.append(words[n - 1].toLowerCase());
        for (int i = 0; i < n - 1; i++){
            sb.append(Character.toLowerCase(words[i].charAt(0)));
        }
        sb.append("@ptit.edu.vn");
        return sb.toString();
    }
    
    public static void main(String[] args) throws SocketException, UnknownHostException, IOException, ClassNotFoundException {
        int port = 2209;
        String message = ";B22DCVT114;YTqTw4Q7";
        System.out.println(message);
        
        DatagramSocket client = new DatagramSocket();
        
        InetAddress server = InetAddress.getByName("203.162.10.109");
        DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
        client.send(out);
        
        byte [] buffer = new byte[1024];
        DatagramPacket in = new DatagramPacket(buffer, buffer.length);
        client.receive(in);
        
        //  Tách RequestID và Object
        byte[]req = Arrays.copyOfRange(in.getData(), 0, 8);
        ByteArrayInputStream bais = new ByteArrayInputStream(in.getData(), 8, in.getLength() - 8);
        ObjectInputStream ois = new ObjectInputStream(bais);
        Student s = (Student) ois.readObject();
        s.info();
        
        //  Chuẩn hóa
        s.setName(fixName(s.getName()));
        s.setEmail(fixEmail(s.getName()));
        s.info();
        
        //  Đóng gói và gửi lên server
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(s);
        oos.flush();
        
        byte [] sendData = new byte[8 + baos.size()];
        System.arraycopy(req, 0, sendData, 0, 8);
        System.arraycopy(baos.toByteArray(), 0, sendData, 8, baos.size());
        DatagramPacket dp = new DatagramPacket(sendData, sendData.length, server, port);
        client.send(dp);
    }
}
