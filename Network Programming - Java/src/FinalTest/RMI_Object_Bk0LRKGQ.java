package FinalTest;

import RMI.ObjectService;
import RMI.Order;
import java.io.*;
import java.rmi.*;
import java.rmi.registry.*;

public class RMI_Object_Bk0LRKGQ {
    public static String getDate(String s){
        StringBuilder sb = new StringBuilder();
        String [] parts = s.split("-");
        String dd = parts[2];
        String mm = parts[1];
        sb.append(parts[2]).append(parts[1]);
        return sb.toString();
    }
    
    public static String genOrderCode(String s, String q, String l){
        StringBuilder sb = new StringBuilder();
        sb.append(s.substring(0,2)).append(q.substring(q.length() - 3));
        sb.append(getDate(l));
        return sb.toString().toUpperCase();
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            ObjectService service = (ObjectService) rg.lookup("RMIObjectService");
            String sCode = "B22DCVT114";
            String qCode = "Bk0LRKGQ";
            Serializable obj = service.requestObject(sCode, qCode);
            
            Order o = (Order) obj;
            System.out.println(o);
            
            String res = genOrderCode(o.getShippingType(), o.getCustomerCode(), o.getOrderDate());
            o.setOrderCode(res);
            System.out.println(o);
            
            service.submitObject(sCode, qCode, o);
            
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
