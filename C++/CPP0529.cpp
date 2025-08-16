// https://code.ptit.edu.vn/student/question/CPP0529
// DANH SÁCH THỰC TẬP - 2

#include <bits/stdc++.h>
using namespace std;

static int cnt = 1;

struct SinhVien {
    string stt, id, name, lop, email, dn;
};

void nhap (SinhVien &a){
    a.stt = to_string(cnt); cnt++;
    getline(cin, a.id);
    getline(cin, a.name);
    getline(cin, a.lop);
    getline(cin, a.email);
    getline(cin, a.dn);
}

void in (SinhVien a){
    cout << a.stt << " " << a.id << " " << a.name << " " << a.lop << " " << a.email << " " << a.dn << endl;
}

bool cmp (SinhVien a, SinhVien b){
    return a.id < b.id;
}

void testcase(SinhVien ds[], int n){
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++){
        if (ds[i].dn == s){
            in(ds[i]);
        }
    }
}

int main(){
    int n; cin >> n;
    cin.ignore();
    struct SinhVien *ds = new SinhVien[n];
    for (int i = 0; i < n; i++){
        nhap(ds[i]);
    }
    sort (ds, ds + n, cmp);
    int q; cin >> q;
    cin.ignore();
    while (q--){
        testcase(ds, n);
    }
}