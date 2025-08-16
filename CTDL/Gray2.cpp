#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; // Đọc số lượng test T
    while (t--) {
        string g;
        cin >> g; // Đọc xâu mã Gray
        int n = g.length(); // Độ dài xâu
        
        string b = g; // Khởi tạo xâu mã nhị phân
        // Công thức: b[i] = g[i] XOR b[i-1]
        // b[0] = g[0]
        for (int i = 1; i < n; i++) {
            // Nếu g[i] và b[i-1] khác nhau, b[i] = 1
            // Nếu g[i] và b[i-1] giống nhau, b[i] = 0
            if (g[i] != b[i - 1]) {
                b[i] = '1';
            } else {
                b[i] = '0';
            }
        }
        
        cout << b << endl; // In xâu mã nhị phân
    }
    return 0;
}