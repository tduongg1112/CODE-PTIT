// https://code.ptit.edu.vn/student/question/CPP0308
// KÝ TỰ KHÔNG LẶP

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int word[26] = {0};
    for (auto x : s){
        word[x - 'A']++;
    }
    for (auto x : s){
        if (word[x - 'A'] == 1){
            cout << x;
        }
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}