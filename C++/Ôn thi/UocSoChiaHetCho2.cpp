// ƯỚC SỐ CHIA HẾT CHO 2

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            if (i % 2 == 0){
                cnt++;
            }
            if ((n / i) % 2 == 0 && i * i != n){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}