package RMI;

import java.rmi.*;
import java.rmi.registry.*;
import java.util.*;

public class RMI_Data_uB4qAf6D {
    public static String findCoin(int amount){
        int [] coins = {10, 5, 2, 1};
        ArrayList<Integer> usedCoins = new ArrayList<>();
        int cnt = 0;
        
        for (int x : coins){
            while (amount >= x){
                amount -= x;
                usedCoins.add(x);
                cnt++;
            }
        }
        if (amount > 0) return "-1";
        
        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append("; ");
        for (int i = 0; i < usedCoins.size(); i++){
            sb.append(usedCoins.get(i)).append(",");
        }
        return sb.toString().replaceAll(",$", "");
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109", 1099);
            DataService service = (DataService) rg.lookup("RMIDataService");
            
            String sCode = "B22DCVT114";
            String qCode = "uB4qAf6D";
            
            Object data = service.requestData(sCode, qCode);
            int amount = (int) data;
            System.out.println("Received: " + amount);
            
            String res = findCoin(amount);
            Object sendData = (Object) res;
            System.out.println("Result: " + sendData);
            
            service.submitData(sCode, qCode, sendData);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
