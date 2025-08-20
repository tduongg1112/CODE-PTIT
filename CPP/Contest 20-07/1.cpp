// Số thuận nghịch

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    string x = s;
    reverse(x.begin(), x.end());
    if (x == s){
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}