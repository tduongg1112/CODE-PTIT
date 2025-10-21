package TCP;

import java.io.*;
import java.net.*;

public class TCP_CharacterStream_6kekIVGi {
    public static void main(String[] args) {
        String host = "203.162.10.109";
        int port = 2208;

        String sCode = "B22DCVT114";
        String qCode = "6kekIVGi";
        String message = sCode + ";" + qCode;

        try (Socket socket = new Socket(host, port)) {
            socket.setSoTimeout(5000);

            // Dùng BufferedReader/Writer (theo đề bài)
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));
            BufferedWriter bw = new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream()));

            // a. Gửi "studentCode;qCode"
            bw.write(message);
            bw.newLine();   // kết thúc dòng để server nhận được
            bw.flush();
            System.out.println("Sent: " + message);

            // b. Nhận danh sách tên miền (1 dòng từ server)
            String domains = br.readLine();
            System.out.println("Received domains: " + domains);

            // c. Lọc tên miền .edu
            StringBuilder eduDomains = new StringBuilder();
            for (String domain : domains.split(",\\s*")) {
                if (domain.endsWith(".edu")) {
                    if (eduDomains.length() > 0) eduDomains.append(", ");
                    eduDomains.append(domain);
                }
            }

            // Gửi danh sách .edu lên server
            bw.write(eduDomains.toString());
            bw.newLine();
            bw.flush();
            System.out.println("Sent edu domains: " + eduDomains);

            // d. Đóng kết nối (try-with-resources tự đóng)
        } catch (SocketTimeoutException e) {
            System.err.println("Timeout! No response from server within 5s.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
