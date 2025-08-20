// https://code.ptit.edu.vn/student/question/CPP0606
// KHAI BÁO LỚP NHÂN VIÊN

#include <bits/stdc++.h>
using namespace std;

class NhanVien {
    public:
        string id = "00001";
        string name, gender, dob, address, tax, signedDay;

    string ChuanHoa (string s){
        if (s[1] == '/') s.insert(0, "0");
        if (s[4] == '/') s.insert(3, "0");
        return s;
    }

    friend istream &operator >> (istream &is, NhanVien &a){
        getline(is, a.name);
        is >> a.gender >> a.dob;
        is.ignore();
        getline(is, a.address);
        is >> a.tax >> a.signedDay;
        return is;
    }
    
    friend ostream &operator << (ostream &os, NhanVien a){
        os << a.id << " " << a.name << " " << a.ChuanHoa(a.dob) << " ";
        os << a.address << " " << a.tax << " " << a.ChuanHoa(a.signedDay);
        return os;
    }
};

int main(){
    NhanVien a;
    cin >> a;
    cout << a;
    return 0;
}