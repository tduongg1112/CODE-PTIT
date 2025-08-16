//M,N,A,B đếm các số trong [M,N] chia hết cho A,B

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, n, a, b;
    cin >> m >> n >> a >> b;
    int cnt = 0;
    for (int i = m; i <= n; i++){
        if (i % a == 0 || i % b == 0){
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}