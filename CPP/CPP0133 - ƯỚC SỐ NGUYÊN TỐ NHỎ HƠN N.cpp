// https://code.ptit.edu.vn/student/question/CPP0133
// ƯỚC SỐ NGUYÊN TỐ NHỎ HƠN N

#include <bits/stdc++.h>
using namespace std;

int n = 1e4;
vector <int> v(n + 1, 1);

void eratosthenes(){
    v[0] = v[1] = 0;
    for (int i = 2; i <= 100; i++){
        if (v[i] == 1){
            for (int j = i * i; j <= n; j += i){
                v[j] = 0;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    for (int i = 2; i <= n; i++){
        if (v[i] == 1){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    eratosthenes();
    int t; cin >> t;
    while(t--){
        solve();
    }
}