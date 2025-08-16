//Tổng chia dư cho K

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    if (k == 0){
        cout << 0 << endl;
        continue;
    }

    long long sum = 0;
    for (long long i = 1; i <= n; i++){
        sum += i % k;
    }
    if (sum == k){
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main (){
    int t; cin >> t;
    while (t--){
        solve();
    }
}