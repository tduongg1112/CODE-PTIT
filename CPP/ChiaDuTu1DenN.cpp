// https://code.ptit.edu.vn/student/question/CPP0153
// CHIA DƯ TỪ 1 ĐẾN N

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += i % k;
    }
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}