// https://code.ptit.edu.vn/student/question/CPP0203
// SỐ NHỎ NHẤT CHƯA XUẤT HIỆN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        if (x >= 1 && x <= n){
            v[x] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        if (v[i] == 0){
            cout << i << endl;
            return;
        }
    }
    cout << n + 1 << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}