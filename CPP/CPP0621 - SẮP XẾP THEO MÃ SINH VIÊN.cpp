// https://code.ptit.edu.vn/student/question/CPP0621
// SẮP XẾP THEO MÃ SINH VIÊN

#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    public:
        string id, name, lop, email;

    friend istream &operator >> (istream &is, SinhVien &a){
        scanf("\n");
        getline(is, a.id);
        getline(is, a.name);
        getline(is, a.lop);
        getline(is, a.email);
        return is;
    }

    friend ostream &operator << (ostream &os, SinhVien a){
        os << a.id << " " << a.name << " " << a.lop << " " << a .email << endl;
        return os;
    }
};

bool cmp (SinhVien a, SinhVien b){
    return a.id < b.id;
}

int main() {
    int n = 0;
    SinhVien ds[1000], x;
    while (cin >> x) {
        ds[n++] = x;
    }
    sort (ds, ds + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << ds[i];
    }
    return 0;
}