// Cho số tự nhiên N và số nguyên tố P. 
// Tìm số x lớn nhất để N! chia hết cho p^x

#include <bits/stdc++.h>
using namespace std;

int max(int n, int p){
    int res = 0;
    while (n){
        res += n / p;
        n /= p;
    }
    return res;
}

void solve(){
    int n; int p;
    cin >> n >> p;
    cout << max(n, p) << endl;
}

int main (){
    int t; cin >> t;
    while (t--){
        solve();
    }
}