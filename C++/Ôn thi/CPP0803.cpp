// https://code.ptit.edu.vn/student/question/CPP0803
// SỐ KHÁC NHAU TRONG FILE

#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream in;
    in.open("DATA.in");

    map<int, int> m;
    int x;
    while (in >> x){
        m[x]++;
    }
    
    for (auto &x : m){
        cout << x.first << " " << x.second << endl;
    }
}