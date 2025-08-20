// https://code.ptit.edu.vn/student/question/CPP0317
// SỐ ĐẸP

#include <bits/stdc++.h>
using namespace std;

bool reversible(string s){
    string res = s;
    reverse(s.begin(), s.end());
    return (res == s);
}

bool even(string s){
    for (auto x : s){
        if ((x - '0') % 2 == 1){
            return false;
        }
    }
    return true;
}

void solve(){
    string n; cin >> n;
    if (reversible(n) && even(n)){
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