// https://code.ptit.edu.vn/student/question/CPP0207
// QUAY VÒNG DÃY SỐ 1

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; int d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < n; i++){
        cout << v[(i + d) % n] << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}