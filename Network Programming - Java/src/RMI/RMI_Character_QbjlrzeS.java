package RMI;

import java.rmi.*;
import java.rmi.registry.*;
import java.util.*;

public class RMI_Character_QbjlrzeS {
    public static String CountChar(String s){
        Map <Character, Integer> map = new LinkedHashMap();
        StringBuilder sb = new StringBuilder();
        
        for (char c : s.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for (Map.Entry<Character, Integer> x : map.entrySet()){
            sb.append(x.getKey()).append(x.getValue());
        }
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            CharacterService service = (CharacterService) rg.lookup("RMICharacterService");
            
            String sCode = "B22DCVT114";
            String qCode = "QbjlrzeS";
            
            String data = service.requestCharacter(sCode, qCode);
            System.out.println("Received: " + data);
            
            String res = CountChar(data);
            System.out.println("Result: " + res);
            
            service.submitCharacter(sCode, qCode, res);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
