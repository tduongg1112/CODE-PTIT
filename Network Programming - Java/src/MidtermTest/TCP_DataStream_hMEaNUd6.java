package MidtermTest;

import java.io.*;
import java.net.*;
import java.util.*;

public class TCP_DataStream_hMEaNUd6 {
    public static String solveCeasar(String s, int n){
        for (char c : s.toCharArray()){
            c = (char) (c - n);
        }
        return s;
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2007;
        String message = "B22DCVT114;hMEaNUd6";
        System.out.println(message);
        
        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            
            out.writeUTF(message);
            out.flush();
            
            String res = in.readUTF();
            int num = in.readInt();
            
            out.flush();
            
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
