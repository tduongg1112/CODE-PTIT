#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    int tmp = 1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int x : a){
        tmp = max(tmp, x);
    }
    cout << tmp << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}