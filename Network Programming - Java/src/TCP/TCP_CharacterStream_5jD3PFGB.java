//  Sắp xếp từ theo độ dài tăng dần

package TCP;

import java.io.*;
import java.net.*;
import java.util.*;

public class TCP_CharacterStream_5jD3PFGB{
    public static final Comparator<String> Word_length = new Comparator<String>(){
        @Override
        public int compare(String a, String b){
            return a.length() - b.length();
        }
    };

    public static void main(String[] args){
        String host = "203.162.10.109";
        int port = 2208;
        int TIMEOUT_MS = 5000;

        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(TIMEOUT_MS);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

            String sCode = "B22DCVT114";
            String qrCode = "5jD3PFGB";
            String request = sCode + ";" + qrCode;

            out.write(request);
            out.write('\n');
            out.flush();

            String input = in.readLine();
            System.out.println(input);
            String[] words = input.split(" ");
            List<String> list = new ArrayList<>(Arrays.asList(words));

            Collections.sort(list, Word_length);

            String res = String.join(", ", list);
            System.out.println(res);

            out.write(res);
            out.write('\n'); 
            out.flush();

        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}