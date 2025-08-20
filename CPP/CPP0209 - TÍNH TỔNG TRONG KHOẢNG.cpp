// https://code.ptit.edu.vn/student/question/CPP0209
// TÍNH TỔNG TRONG KHOẢNG

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; int q;
    cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }
}

int main (){
    int t; cin >> t;
    while(t--){
        solve();
    }
}