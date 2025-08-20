// https://code.ptit.edu.vn/student/question/CPP0103
// TÍNH TỔNG PHÂN THỨC

#include <bits/stdc++.h>
using namespace std;

int n;

void solve(){
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++){
        sum += (1.0/i);
    }
    cout << fixed << setprecision(4) << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}