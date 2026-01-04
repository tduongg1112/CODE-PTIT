// Binary to Hexa

package FinalTest;

import RMI.ByteService;
import java.util.*;
import java.rmi.*;
import java.rmi.registry.*;

public class RMI_Byte_7bAHD6Pj {
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            ByteService service = (ByteService) rg.lookup("RMIByteService");
            
            String sCode = "B22DCVT114";
            String qCode = "7bAHD6Pj";
            
            byte [] data = service.requestData(sCode, qCode);
            System.out.println("Received: " + Arrays.toString(data));
            
            String hex = new String();
            for (byte x : data){
                hex += Integer.toHexString(x);
            }
            
            service.submitData(sCode, qCode, hex.getBytes());
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
