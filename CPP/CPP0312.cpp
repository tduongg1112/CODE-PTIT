// https://code.ptit.edu.vn/student/question/CPP0312
// XÂU PANGRAM

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    int k;
    cin >> s >> k;
    int d[26] = {0};
    for (auto x : s){
        d[x - 'a']++;   //Đánh STT cho a - z thành 0 - 25
                        //Tăng trong mảng đánh dấu
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++){
        if (d[i] == 0){
            cnt++;
        }
    }
    if (cnt <= k){
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}