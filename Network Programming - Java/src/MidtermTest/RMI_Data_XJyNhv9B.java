package MidtermTest;

import RMI.DataService;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.*;

public class RMI_Data_XJyNhv9B {
    public static int thirdMax (String s){
        String [] parts = s.split("; ");
        String [] words = parts[0].split(", ");
        int k = Integer.parseInt(parts[1]);
        
        ArrayList<Integer> nums = new ArrayList<>();
        
        for (String x : words){
            nums.add(Integer.parseInt(x));
        }
        Collections.sort(nums);
        int res = nums.get(nums.size() - k);
        return res;
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            DataService service = (DataService) rg.lookup("RMIDataService");
            
            String sCode = "B22DCVT114";
            String qCode = "XJyNhv9B";
            
            Object response = service.requestData(sCode, qCode);
            String data = (String) response;
            System.out.println("Received: " + response);
            
            int res = thirdMax(data);
            System.out.println("Result: " + res);
            service.submitData(sCode, qCode, res);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
