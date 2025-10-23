package MidtermTest;

import RMI.ObjectService;
import RMI.ProductX;
import java.io.Serializable;
import java.rmi.*;
import java.rmi.registry.*;

public class RMI_Object_GO2DawAk {
    public static int sum (String s){
        int sum = 0;
        for (char c : s.toCharArray()){
            if (Character.isDigit(c)){
                sum += Character.getNumericValue(c);
                //  sum += c - '0';
            }
        }
        return sum;
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            ObjectService service = (ObjectService) rg.lookup("RMIObjectService");
            
            String sCode = "B22DCVT114";
            String qCode = "GO2DawAk";
            
            Serializable obj = service.requestObject(sCode, qCode);
            ProductX p = (ProductX) obj;
            System.out.println(p);
            
            p.setDiscount(sum(p.getDiscountCode()));
            System.out.println(p);
            
            service.submitObject(sCode, qCode, p);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
