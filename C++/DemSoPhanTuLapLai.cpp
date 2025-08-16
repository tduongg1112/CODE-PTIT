#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    vector<int> v(1e6 + 5, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        v[a[i]]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(v[a[i]] >= 2){
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}