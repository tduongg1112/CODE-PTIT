// https://code.ptit.edu.vn/student/question/CPP0115
// PHÂN TÍCH THỪA SỐ NGUYÊN TỐ - 1

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int cnt = 0;
            while (n % i == 0){
                n /= i;
                cnt++;
            }
            cout << i << " " << cnt << endl;
        }
        if (n == 1){
            break;
        }
    }
    if (n > 1){
        cout << n << " " << 1;
    }
    cout << endl;
}

int main (){
    int t; cin >> t;
    while(t--){
        solve();
    }
}