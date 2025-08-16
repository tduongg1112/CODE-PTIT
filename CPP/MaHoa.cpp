// https://code.ptit.edu.vn/student/question/CPP0354
// MÃ HÓA

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin, s);
    int cnt = 1;
    for (int i = 1; i <= s.length(); i++){
        if (s[i] == s[i - 1] && i < n){
            cnt++;
        } else {
            cout << s[i - 1] << cnt;
            cnt = 1;
        }
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
}