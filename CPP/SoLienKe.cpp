#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); ++i) {
        if (abs(s[i] - s[i - 1]) != 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}