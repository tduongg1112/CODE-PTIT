package FinalTest;

import RMI.CharacterService;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.*;

public class RMI_Character_RD2p7MUp {
    public static String countFreq (String s){
        StringBuilder sb = new StringBuilder();
        Map <Character, Integer> map = new LinkedHashMap<>();
        for (char c : s.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        
        for (Character c : map.keySet()){
            sb.append(c);
            sb.append(map.get(c));
        }
        
        for (Map.Entry<Character, Integer> x : map.entrySet()){
            sb.append(x.getKey());
            sb.append(x.getValue());
        }
        
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            CharacterService service = (CharacterService) rg.lookup("RMICharacterService");
            
            String sCode = "B22DCVT036";
            String qCode = "RD2p7MUp";
            
            String receive = service.requestCharacter(sCode, qCode);
            String res = countFreq(receive);
            service.submitCharacter(sCode, qCode, res);
            
        } catch (Exception e) {
        }
    }
}
