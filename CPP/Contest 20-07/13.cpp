#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int res = 0;
    
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int count1 = a + b + c;
        int count0 = 3 - count1;

        if (count1 > count0){
            res++;
        }
    }
    cout << res << endl;
}

int main (){
    solve();
}