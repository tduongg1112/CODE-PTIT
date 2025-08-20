// https://code.ptit.edu.vn/student/question/JP012
// LIỆT KÊ SỐ FIBONACCI

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a, b;
    cin >> a >> b;
    vector <ll> f(94);
    f[1] = f[2] = 1;
    for (int i = 3; i <= 93; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = a; i <= b; i++){
        cout << f[i] << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}