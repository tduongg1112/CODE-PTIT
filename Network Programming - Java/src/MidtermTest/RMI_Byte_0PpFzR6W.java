// Encode Ceasar Cipher

package MidtermTest;

import RMI.ByteService;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.Arrays;

public class RMI_Byte_0PpFzR6W {
    public static byte [] encodeCeasar(byte [] data){
        int n = data.length;
        byte [] res = new byte[n];
        for (int i = 0; i < n; i++){
            res[i] = (byte) (data[i] + n);
        }
        return res;
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            ByteService service = (ByteService) rg.lookup("RMIByteService");
            String sCode = "B22DCVT114";
            String qCode = "0PpFzR6W";
            
            byte [] data = service.requestData(sCode, qCode);
            System.out.println("Received: " + Arrays.toString(data));
            System.out.println("Shift: " + data.length);
            
            byte [] res = encodeCeasar(data);
            System.out.println("Result: " + Arrays.toString(res));
            
            service.submitData(sCode, qCode, res);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
