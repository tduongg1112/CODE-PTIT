// https://code.ptit.edu.vn/student/question/CPP0325
// CHIA HẾT CHO 11

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    long long res = 0;
    for (auto x : s){
        res = res * 10 + (x - '0');
        res %= 11;
    }
    if (res == 0){
        cout << 1 << endl;
    } else cout << 0 << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}