// https://code.ptit.edu.vn/student/question/CPP0107
// CHẤM ĐIỂM TRẮC NGHIỆM

#include <bits/stdc++.h>
using namespace std;

string a = "ABBADCCABDCCABD";
string b = "ACCABCDDBBCDDBB";

void solve(){
    int n;
    cin >> n;
    double point = 0;
    if (n == 101){
        for (int i = 0; i < 15; i++){
            char c;
            cin >> c;
            if (c == a[i]){
                point += 2.0/3;
            }
        }
    }
    else if (n == 102){
        for (int i = 0; i < 15; i++){
            char c;
            cin >> c;
            if (c == b[i]){
                point += 2.0/3;
            }
        }
    }
    cout << fixed << setprecision(2) << point << endl;
}

int main (){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}