//Phân tích thừa số nguyên tố

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    for (long long i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int cnt = 0;
            while (n % i == 0){
                n /= i;
                cnt++;
            }
            cout << i << " " << cnt << endl;
        }
    }
    if (n > 1){
        cout << n << " " << 1;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        solve();
    }
}