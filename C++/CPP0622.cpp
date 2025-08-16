// https://code.ptit.edu.vn/student/question/CPP0622
// LIỆT KÊ SINH VIÊN THEO LỚP

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

    friend ostream &operator << (ostream &os, const SinhVien &a){
        os << a.id << " " << a.name << " " << a.lop << " " << a.email << endl; 
        return os;
    }
};

void testcase(SinhVien ds[], int n, string s){  
    cout << "DANH SACH SINH VIEN LOP " << s << ":" << endl;
    for (int i = 0; i < n; i++){
        if (ds[i].lop == s){
            cout << ds[i];
        }
    }
}

int main(){
    SinhVien ds[1000];
    int n; cin >> n;
    for (int i = 0 ; i < n; i++){
        cin >> ds[i];
    }
    int q; cin >> q;
    cin.ignore();
    while (q--){
        string s;
        getline(cin, s);
        testcase(ds, n, s);
    }
    return 0;
}