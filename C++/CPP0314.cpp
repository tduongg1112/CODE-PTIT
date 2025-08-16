// https://code.ptit.edu.vn/student/question/CPP0314
// CHÚC MỪNG NĂM MỚI

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    cin.ignore();
    set<string> list;
    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        list.insert(s);
    }
    cout << list.size() << endl;
}

int main(){
    solve();
}