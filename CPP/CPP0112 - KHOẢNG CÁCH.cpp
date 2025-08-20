// https://code.ptit.edu.vn/student/question/CPP0112
// KHOẢNG CÁCH

#include <bits/stdc++.h>
using namespace std;

void solve(){
    double x1, x2, y1 , y2;
    cin >> x1 >> x2 >> y1 >> y2;
    double res = sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
    cout << fixed << setprecision(4) << res << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}