// https://code.ptit.edu.vn/student/question/CPP0804
// LIỆT KÊ TỪ KHÁC NHAU

#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream in;
    in.open("VANBAN.in");

    map <string, int> m;
    string word;

    while (in >> word){
        for (auto &c : word){
            c = tolower(c);
        }
        m[word]++;
    }

    for (auto &x : m){
        cout << x.first << endl;
    }
    in.close();
}