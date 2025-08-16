#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
vector<int> b;

void solve(){
    for (int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try (int i){
    for (int j = a[i - 1] + 1; j <= n - k + i; j++){
        a[i] = j;
        if (i == k){
            solve();
        }
        else {
            Try(i + 1);
        }
    }
}

void testCase(){
    cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x; 
        s.insert(x);
    }
    int g = s.size();
    Try(1);
}

int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        a.resize(n);
        Try(1);
    }
}