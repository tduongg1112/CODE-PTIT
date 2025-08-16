#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if (n < 2){
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

void solve(){
    long long n; cin >> n;
    long long res;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (isPrime(n / i)) {
                cout << n / i << endl;
                return;
            }
            if (isPrime(i))
                res = i;
        }
    }
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}