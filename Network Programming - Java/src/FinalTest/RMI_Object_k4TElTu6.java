package FinalTest;

import RMI.ObjectService;
import RMI.ProductX;
import java.rmi.*;
import java.rmi.registry.*;

public class RMI_Object_k4TElTu6 {
    public static int updateDiscount(String s){
        int sum = 0;
        for (char c : s.toCharArray()){
            if (Character.isDigit(c)){
                sum += Character.getNumericValue(c);
            }
        }
        return sum;
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            ObjectService service = (ObjectService) rg.lookup("RMIObjectService");
            
            String sCode = "B22DCVT036";
            String qCode = "k4TElTu6";
            
            Object data = service.requestObject(sCode, qCode);
            ProductX p = (ProductX) data;
            
            p.setDiscount(updateDiscount(p.getDiscountCode()));
            service.submitObject(sCode, qCode, p);
            
        } catch (Exception e) {
        }
    }
}
