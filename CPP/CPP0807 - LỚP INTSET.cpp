// https://code.ptit.edu.vn/student/question/CPP0807
// LỚP INTSET

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    set <int> s1, s2;

    ifstream file;
    file.open("DATA.in");

    file >> n >> m;
    for (int i = 0; i < n; i++){
        file >> x;
        s1.insert(x);
    }
    for (int i = 0; i < m; i++){
        file >> x;
        s2.insert(x);
    }

    map <int, int> M;
    for (auto x : s1) M[x]++;
    for (auto x : s2) M[x]++;

    for (auto &x : M){
        if (x.second == 2){
            cout << x.first << " ";
        }
    }
    file.close();
}