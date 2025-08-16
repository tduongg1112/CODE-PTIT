// https://code.ptit.edu.vn/student/question/CPP0339
// ĐẦU CUỐI GIỐNG NHAU

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int d = s.length();
    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        int p = i + 1;
        while (s.find(c, p) != -1)
        {
            p = s.find(c, p) + 1;
            d++;
        }
    }
    cout << d << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}