// https://code.ptit.edu.vn/student/question/CPP0412
// SẮP XẾP 0 - 1 - 2

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort (v.begin(), v.end());
    for (auto x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}