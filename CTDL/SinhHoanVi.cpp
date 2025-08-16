#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;

void solve(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << " ";
}

void sinh(int i){
    for (int j = 1; j <= n; j++){
        if (!b[j]){
            a[i] = j;
            b[j] = 1;
            if (i == n) {
                solve();
            }
            else {
                sinh(i + 1);
            }
            b[j] = 0;
        }
    }
}

void testCase (){
    cin >> n;
    a.resize(n + 1);
    b.clear();
    b.resize(n + 1, 0);
    sinh(1);
}

int main (){
    int t;
    cin >> t;
    while (t--){
        testCase();
        cout << endl;
    }
}