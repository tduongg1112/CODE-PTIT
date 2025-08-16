#include <bits/stdc++.h>
using namespace std;

int n;
int k;
vector<int> a;

void solve(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == 1) cnt++;
    }
    if (cnt == k){
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
    }
}

void Try(int i){
    for (int j = 0; j <= 1; j++){
        a[i] = j;
        if (i == n){
            solve();
        }
        else {
            Try(i + 1);
        }
    }
}

void testCase(){
    cin >> n >> k;
    a.resize(n + 1);
    Try(1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        testCase();
        cout << endl;
    }
}