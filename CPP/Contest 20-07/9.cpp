//Mảng đánh dấu

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int max = 1e6 + 5;
    int freq[max];

    for (int i = 0; i < max; i++){
        freq[i] = 0;
    }
    
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (freq[a[i]] > 1){
            cnt++;
        }
    }
    cout << cnt << endl;
    
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        solve();
    }
}