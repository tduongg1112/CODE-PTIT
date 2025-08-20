// https://code.ptit.edu.vn/student/question/CPP0309
// ĐẾM TỪ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; string x;
    getline(cin, s);
    stringstream ss(s);
    int cnt = 0;
    while (ss >> x){
        cnt++;
    }
    cout << cnt << endl;
}

int main(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
}