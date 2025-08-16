#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    long long res = 0;
    for (auto x : s){
        res = res * 2 + (x - '0');
        res %= 5;
    }
    if (res == 0){
        cout << "Yes" << endl;
    } else cout << "No" << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}