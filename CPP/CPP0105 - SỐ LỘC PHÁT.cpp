// https://code.ptit.edu.vn/student/question/CPP0105
// SỐ LỘC PHÁT

#include <bits/stdc++.h>
using namespace std;

string s;

void solve(){
    cin >> s;
    for (auto x : s){
        if (x != '0' && x != '6' && x != '8'){
            cout << "NO" << endl;
            return; // Thoát khỏi solve()
        }
    }
    cout << "YES" << endl;
}

int main (){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}