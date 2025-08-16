// https://code.ptit.edu.vn/student/question/CPP0413
// SẮP XẾP XEN KẼ - 1

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector <int> v(n);
    for (auto &x : v){
        cin >> x;
    }
    sort(v.begin(), v.end(), greater<int>());
    int i = 0;
    int j = n - 1;
    while (i < j){
        cout << v[i++] << " ";
        if (i != j){
            cout << v[j--] << " ";
        }
    }
    if (i == j){
        cout << v[i];
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}