// https://code.ptit.edu.vn/student/question/CPP0620
// SẮP XẾP SINH VIÊN THEO LỚP

#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string maSV, hoTen, lop, email;
    public:
        void nhap(){
            cin >> maSV;
            cin.ignore();
            getline(cin, hoTen);
            cin >> lop >> email;
        }
        void in(){
            cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
        }
        string getLop(){
            return lop;
        }
        string getMaSV(){
            return maSV;
        }
};

bool cmp (SinhVien a, SinhVien b){
    if (a.getLop() != b.getLop()){
        return a.getLop() < b.getLop();
    } else {
        return a.getMaSV() < b.getMaSV();
    }
}

int main(){
    int n; cin >> n;
    SinhVien sv[n];
    for (int i = 0; i < n; i++){
        sv[i].nhap();
    }
    sort(sv, sv + n, cmp);
    for (int i = 0; i < n; i++){
        sv[i].in();
    }
}