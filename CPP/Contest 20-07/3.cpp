// Rút gọn số

#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    while (n >= 10){
        int sum = 0;
        while (n > 0){
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main (){
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}