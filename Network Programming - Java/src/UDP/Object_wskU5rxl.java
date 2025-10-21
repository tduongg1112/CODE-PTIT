package UDP;

import java.io.*;
import java.net.*;

public class Object_wskU5rxl {
    public static String fixName(String s){
        String [] words = s.toLowerCase().split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++){
            sb.append(Character.toUpperCase(words[i].charAt(0)));
            sb.append(words[i].substring(1));
            sb.append(" ");
        }
        return sb.toString().trim();
    }
    
    public static double upSalary(String date, double salary){
        String [] parts = date.split("/");
        String y = parts[2];
        int n = Integer.parseInt(y);
        int sum = 0;
        while (n > 0){
            sum += n % 10;
            n /= 10;
        }
        double newSalary = salary + salary * sum / 100.0;
        newSalary = Math.round(newSalary * 100.0)/100.0;
        return newSalary;
    }
    
    public static String fixDate (String s){
        String [] parts = s.split("-");
        return parts[2] + "/" + parts[1] + "/" + parts[0];
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2209;
        String message = ";B22DCVT114;wskU5rxl";
        System.out.println(message);
        
        try(DatagramSocket client = new DatagramSocket()){
            InetAddress server = InetAddress.getByName(host);
            DatagramPacket out = new DatagramPacket(message.getBytes(), message.length(), server, port);
            client.send(out);
            
            byte[] buffer = new byte[4096];
            DatagramPacket in = new DatagramPacket(buffer, buffer.length);
            client.receive(in);
            
            String reqId = new String(in.getData(), 0, 8);
            ByteArrayInputStream bais = new ByteArrayInputStream(in.getData(), 8, in.getLength() - 8);
            ObjectInputStream ois = new ObjectInputStream(bais);
            Employee e = (Employee) ois.readObject();
            System.out.println(e);
            
            e.setName(fixName(e.getName()));
            e.setHireDate(fixDate(e.getHireDate()));
            e.setSalary(upSalary(e.getHireDate(), e.getSalary()));
            System.out.println(e);

            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(e);
            oos.flush();
            
            byte[] sendData = new byte[8 + baos.size()];
            System.arraycopy(reqId.getBytes(), 0, sendData, 0, 8);
            System.arraycopy(baos.toByteArray(), 0, sendData, 8, baos.size());
            DatagramPacket dp = new DatagramPacket(sendData, sendData.length, server, port);
            client.send(dp);
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
