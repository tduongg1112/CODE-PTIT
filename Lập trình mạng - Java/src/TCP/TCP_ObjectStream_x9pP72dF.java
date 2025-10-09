package TCP;

import java.io.*;
import java.net.*;

public class TCP_ObjectStream_x9pP72dF implements Serializable{
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2209;
        
        String sCode = "B22DCVT114";
        String qCode = "x9pP72dF";
        String message = sCode + ";" + qCode;
        
        try (Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            
            
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
