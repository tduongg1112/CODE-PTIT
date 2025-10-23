//  Đảo ngược từ và mã hóa RLE

package TCP;

import java.io.*;
import java.net.*;

public class TCP_CharacterStream_sP0pI45x {
    public static String reverse(String s){
        return new StringBuilder(s).reverse().toString();
    }
    
    public static String encode(String s){
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        int n = s.length();
        for (int i = 1; i < n; i++){
            if (s.charAt(i) == s.charAt(i - 1)){
                cnt++;
            } else {
                sb.append(s.charAt(i - 1));
                if (cnt > 1) sb.append(cnt);
                cnt  = 1;
            }
        }
        sb.append(s.charAt(n - 1));
        if (cnt > 1) sb.append(cnt);
        return sb.toString();
    }
    
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;
        
        String sCode = "B22DCVT114";
        String qCode = "sP0pI45x";
        String message = sCode + ";" + qCode;
        System.out.println(message);
        
        try(Socket socket = new Socket(host, port)){
            socket.setSoTimeout(5000);
            
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            
            out.write(message);
            out.newLine();
            out.flush();
            System.out.println("MESSAGE: " + message);
            
            String response = in.readLine();
            String [] words = response.split(" ");
            for (int i = 0; i < words.length; i++){
                words[i] = reverse(words[i]);
            }
            String reversed = String.join(" ", words);
            String result = encode(reversed);
            System.out.println("RESULT: " + result);
            
            out.write(result);
            out.newLine();
            out.flush();
            
            socket.close();
            
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
