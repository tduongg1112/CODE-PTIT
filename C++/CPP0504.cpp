// https://code.ptit.edu.vn/student/question/CPP0504
// CÁU TRÚC SINH VIÊN

#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string id;
    string name;
    string grade;
    string dob;
    double gpa;
};

void nhap(SinhVien &x){
    getline(cin, x.name);
    getline(cin, x.grade);
    getline(cin, x.dob);
    cin >> x.gpa;
}

string ChuanHoa(string s){
    if (s[1] == '/') s.insert(0, "0");
    if (s[4] == '/') s.insert(3, "0");
    return s;
}

void in(SinhVien x){
    cout << "B20DCCN001" << " " << x.name << " " << x.grade << " ";
    cout << ChuanHoa(x.dob) << " " << fixed << setprecision(2) << x.gpa << endl;
}

int main(){
    struct SinhVien a;
    nhap(a);
    in(a);
    return 0;
}