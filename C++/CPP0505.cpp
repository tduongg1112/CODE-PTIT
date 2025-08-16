// https://code.ptit.edu.vn/student/question/CPP0505
// CẤU TRÚC NHÂN VIÊN

#include <bits/stdc++.h>
using namespace std;

struct NhanVien {
    string id = "00001";
    string name;
    string gender;
    string dob;
    string address;
    string tax;
    string signedDay;
};

string ChuanHoa(string s){
    if (s[1] == '/') s.insert(0, "0");
    if (s[4] == '/') s.insert(3, "0");
    return s;
}

string ChuanHoa_2(string s){
    if (s.length() == 8){
        return '0' + s.substr(0,2) + '0' + s.substr(2);
    } else if (s.length() == 9){
        if (s[1] == '/'){
            return '0' + s;
        }
        else {
            return s.substr(0,3) + '0' + s.substr(3);
        }
    }
    return s;
}

void nhap(NhanVien &x){
    getline(cin, x.name);
    getline(cin, x.gender);
    getline(cin, x.dob);
    getline(cin, x.address);
    getline(cin, x.tax);
    getline(cin, x.signedDay);
}

void in (NhanVien x){
    cout << x.id << " " << x.name << " " << x.gender << " ";
    cout << ChuanHoa(x.dob) << " " << x.address << " ";
    cout << x.tax << " " << ChuanHoa(x.signedDay);
}

int main(){
    struct NhanVien a;
    nhap(a);
    in(a);
    return 0;
}