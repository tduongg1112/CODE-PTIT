// Đếm tần suất xuất hiện ký tự trong chuỗi

package FinalTest;

import RMI.CharacterService;
import java.rmi.*;
import java.rmi.registry.*;
import java.util.LinkedHashMap;
import java.util.Map;

public class RMI_Character_WzSnX3f8 {
    public static String countFrequency (String s){
        Map<Character, Integer> map = new LinkedHashMap();
        for (char c : s.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        for (Map.Entry<Character, Integer> entry : map.entrySet()){
            sb.append("\"");
            sb.append(entry.getKey());
            sb.append("\": ");
            sb.append(entry.getValue());
            sb.append(", ");
        }
        sb.delete(sb.length() - 2, sb.length());
        sb.append("}");
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
            Registry rg = LocateRegistry.getRegistry("203.162.10.109");
            CharacterService service = (CharacterService) rg.lookup("RMICharacterService");
            
            String sCode = "B22DCVT114";
            String qCode = "WzSnX3f8";
            
            String data = service.requestCharacter(sCode, qCode);
            System.out.println("Received: " + data);
            
            String res = countFrequency(data);
            System.out.println("Result: " + res);
            service.submitCharacter(sCode, qCode, res);
            
        } catch (Exception e) {
            e.getStackTrace();
        }
    }
}
