// https://code.ptit.edu.vn/student/question/CPP0102
// CHỮ HOA – CHỮ THƯỜNG

#include <bits/stdc++.h>
using namespace std;

char c;

void solve(){
    
    if (isupper(c)){
        cout << (char)tolower(c) << endl;
    } else if (islower(c)){
        cout << (char)toupper(c) << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> c;
        solve();
    }
}