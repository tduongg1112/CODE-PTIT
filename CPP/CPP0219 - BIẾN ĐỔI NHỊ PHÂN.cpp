// https://code.ptit.edu.vn/student/question/CPP0219
// BIẾN ĐỔI NHỊ PHÂN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    bool row[n] = {0};
    bool col[m] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            if (x == 1){
                row[i] = 1;
                col[j] = 1; 
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (row[i] || col[j])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}