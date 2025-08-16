// https://code.ptit.edu.vn/student/question/CPP204C4000
// CẤU TRÚC SINH VIÊN

#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string id, name, lop, dob;
    double gpa;
};

string ChuanHoa(string s){
    if (s[1] == '/') s.insert(0, "0");
    if (s[4] == '/') s.insert(3, "0");
    return s;
}

void nhapThongTinSV(SinhVien &a){
    a.id = "N20DCCN001";
    getline(cin, a.name);
    cin >> a.lop >> a.dob >> a.gpa;
}

void inThongTinSV(SinhVien a){
    cout << a.id << " " << a.name << " " << a.lop << " ";
    cout << ChuanHoa(a.dob) << " " << fixed << setprecision(2) << a.gpa << endl;
}

int main(){
    struct SinhVien a;
    nhapThongTinSV(a);
    inThongTinSV(a);
    return 0;
}