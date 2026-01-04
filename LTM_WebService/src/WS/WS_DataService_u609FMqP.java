package WS;

import java.util.ArrayList;
import java.util.List;
import vn.medianews.*;

public class WS_DataService_u609FMqP {
    public static void main(String[] args) {
        DataService_Service sv = new DataService_Service();
        DataService mixi = sv.getDataServicePort();
        
        String sCode = "B22DCVT114";
        String qCode = "u609FMqP";
        
        List <Integer> receive = mixi.getData(sCode, qCode);
        List <String> convert = new ArrayList<>();
        
        for (Integer x : receive){
            String octa = Integer.toOctalString(x);
            String hexa = Integer.toHexString(x).toUpperCase();
            convert.add(octa + "|" + hexa);
        }
        mixi.submitDataStringArray(sCode, qCode, convert);
    }
}
