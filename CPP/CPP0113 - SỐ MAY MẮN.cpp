// https://code.ptit.edu.vn/student/question/CPP0113
// SỐ MAY MẮN

#include <bits/stdc++.h>
using namespace std;

void TestCase(){
    string s;
    cin >> s;
    int l = s.length();

    if (l == 1) {
        cout << "0" << endl;
    } else {
        string last = s.substr(l - 2, 2);
        if (last == "86") {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        TestCase();
    }
    return 0;
}