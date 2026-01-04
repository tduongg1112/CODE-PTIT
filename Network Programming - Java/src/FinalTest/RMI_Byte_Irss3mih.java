package FinalTest;

import RMI.ByteService;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.Arrays;

public class RMI_Byte_Irss3mih {
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            ByteService service = (ByteService) rg.lookup("RMIByteService");
            
            String sCode = "B22DCVT036";
            String qCode = "Irss3mih";
            
            byte [] data = service.requestData(sCode, qCode);
            System.out.println("Received: " + Arrays.toString(data));
            
            byte [] res = new byte[data.length];
            int index = 0;
            
            for (int i = 0; i < res.length; i++){
                if (data[i] % 2 == 0){
                    res[index++] = data[i]; 
                }
            }
            
            for (int i = 0; i < res.length; i++){
                if (data[i] % 2 != 0){
                    res[index++] = data[i];
                }
            }
            
            System.out.println("Result: " + Arrays.toString(res));
            service.submitData(sCode, qCode, res);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
