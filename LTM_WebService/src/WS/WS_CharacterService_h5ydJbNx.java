package WS;

import java.util.List;
import vn.medianews.CharacterService;
import vn.medianews.CharacterService_Service;


public class WS_CharacterService_h5ydJbNx {
    public static void main(String[] args) {
        CharacterService_Service sv = new CharacterService_Service();
        CharacterService mixi = sv.getCharacterServicePort();
        
        String sCode = "B22DCVT114";
        String qCode = "h5ydJbNx";
        
        List<String> data = mixi.requestStringArray(sCode, qCode);
        
        
    }
    
}
