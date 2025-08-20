#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // bỏ dòng newline sau số nguyên

    set<string> uniqueWishes;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        uniqueWishes.insert(s); // set tự động lọc trùng
    }

    cout << uniqueWishes.size() << endl;

    return 0;
}