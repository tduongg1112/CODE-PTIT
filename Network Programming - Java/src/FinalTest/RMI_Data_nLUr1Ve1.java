// Anh tung ngay đồng xu

package FinalTest;

import RMI.DataService;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.ArrayList;

public class RMI_Data_nLUr1Ve1 {
    public static String findCoin(int amount){
        int [] coins = {10, 5 , 2, 1};
        ArrayList <Integer> usedCoins = new ArrayList<>();
        int cnt = 0;
        
        for (int x : coins){
            while (amount >= x){
                usedCoins.add(x);
                amount -= x;
                cnt++;
            }
        }
        
        if (amount > 0) return "-1";
        
        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append("; ");
        for (int x : usedCoins){
            sb.append(x).append(",");
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            DataService service = (DataService) rg.lookup("RMIDataService");
            
            String sCode = "B22DCVT036";
            String qCode = "nLUr1Ve1";
            
            Object data = service.requestData(sCode, qCode);
            int amount = (int) data;
            
            Object res = (Object) findCoin(amount);
            service.submitData(sCode, qCode, res);
            
        } catch (Exception e) {
        }
    }
}
