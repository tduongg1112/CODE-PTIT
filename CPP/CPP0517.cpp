// https://code.ptit.edu.vn/student/question/CPP0517
// DANH SÁCH NHÂN VIÊN

#include <bits/stdc++.h>
using namespace std;

struct NhanVien {
    string id, name, gender, dob, address, tax, signedDay;
};

void nhap(NhanVien &x){
    scanf("\n");
    getline(cin, x.name);
    getline(cin, x.gender);
    getline(cin, x.dob);
    getline(cin, x.address);
    getline(cin, x.tax);
    getline(cin, x.signedDay);
}

string STT(int i){
    string r = to_string(i);
    while (r.length() < 5){
        r = '0' + r;
    }
    return r;
}

string ChuanHoa(string s){
    if (s[1] == '/') s.insert(0, "0");
    if (s[4] == '/') s.insert(3, "0");
    return s;
}

void inds(NhanVien ds[], int n){
    for (int i = 0; i < n; i++){
        ds[i].id = STT(i + 1);
        cout << ds[i].id << " ";
        cout << ds[i].name << " " << ds[i].gender << " " << ChuanHoa(ds[i].dob) << " " << ds[i].address << " " << ds[i].tax << " " << ChuanHoa(ds[i].signedDay) << endl;
    }
}

int main(){
    struct NhanVien ds[50];
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++){
        nhap(ds[i]);
    } 
    inds(ds, n);
    return 0;
}