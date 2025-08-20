// https://code.ptit.edu.vn/student/question/CPP0139
// SỐ SMITH

#include <bits/stdc++.h>
using namespace std;

int sum (int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isPrime (int n){
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

void solve(){
    int n; cin >> n;
    if (isPrime(n)){
        cout << "NO" << endl;
        return;
    }
    int s1 = sum(n);
    int s2 = 0;
    for (int i = 2; i <= sqrt(n); i++){
        while (n % i == 0){
            s2 += sum(i);
            n /= i;
        }
        if (n == 1) break;
    }
    if (n > 1){
            s2 += sum(n);
        }

    if (s1 == s2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}