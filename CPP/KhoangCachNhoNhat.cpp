#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    int tmp = 1e6;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++){
        tmp = min(tmp, a[i] -  a[i - 1]);
    }
    cout << tmp << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}