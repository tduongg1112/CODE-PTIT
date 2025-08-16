#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

void solve(){
    for (int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i){
    for (int j = a[i - 1] + 1; j < n - k + i; j++){
        a[j]++;
    }
    if (i == k){
        solve();
    }
    else {
        Try(i + 1);
    }
}

void testCase(){
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        cin >> a[i];
    }
    a.resize(n + 1);
    Try(1);
}

int main (){
    int t;
    cin >> t;
    while (t--){
        testCase();
        cout << endl;
    }
}