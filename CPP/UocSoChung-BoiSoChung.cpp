#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b){
    while (b != 0){
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}

ll lcm(int a, int b){
    return (long long)a * b / gcd(a, b);
}

void solve(){
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << " " << gcd(a, b) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}