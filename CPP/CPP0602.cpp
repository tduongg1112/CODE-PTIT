// https://code.ptit.edu.vn/student/question/CPP0602
// KHAI BÁO LỚP SINH VIÊN - 2

#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    public:
        string id = "B20DCCN001", name, lop, dob;
        double gpa;
    
    string ChuanHoa(string s){
        if (s[1] == '/') s.insert(0, "0");
        if (s[4] == '/') s.insert(3, "0");
        return s;
    }

    friend istream &operator >> (istream &is, SinhVien &a){
        getline(is, a.name);
        is >> a.lop >> a.dob >> a.gpa;
        return is;
    }

    friend ostream &operator << (ostream &os, SinhVien a){
        os << a.id << " " << a.name << " " << a.lop << " " << a.ChuanHoa(a.dob) << " ";
        os << fixed << setprecision(2) << a.gpa;
        return os;
    }
        
};



int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}