// https://code.ptit.edu.vn/student/question/CPP0118
// SỐ SPHENIC

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            cnt++;
            int power = 0;
            while (n % i == 0){
                n /= i;
                power++;
            }
            if (power > 1){
                cout << 0 << endl;
                return;
            }
        }
    }
    if (n > 1){
        cnt++;
    }

    if (cnt == 3){
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}