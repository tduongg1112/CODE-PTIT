// https://code.ptit.edu.vn/student/question/CPP0216
// DÃY MOUNTAIN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l, r;
    cin >> l >> r;
    while (l <= r && a[l] <= a[l + 1]){
        l++;
    }
    l++;
    while (l <= r && a[l] <= a[l - 1]){
        l++;
    }

    if (l > r){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}