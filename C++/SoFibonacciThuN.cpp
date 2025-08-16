#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fibo(int n){
    vector<ll> f(93);
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fibo(n) << endl;
    }
}