#include <bits/stdc++.h>;
using namespace std;

class SinhVien {
    private:
        string maSV, hoTen, lop, ngaySinh;
        float GPA;
    public:
        SinhVien() {
            maSV = "";
            hoTen = "";
            lop = "";
            ngaySinh = "";
            GPA = 0;
        }
        void nhap() {
            maSV = "B20DCCN001";
            getline(cin, hoTen);
            cin >> lop >> ngaySinh >> GPA;
            if (ngaySinh[1] == '/') ngaySinh.insert(0, "0"); 
            if (ngaySinh[4] == '/') ngaySinh.insert(3, "0");
        }
        void xuat() {
            cout << maSV << " " << hoTen << " " << lop << " " << ngaySinh << " " << fixed << setprecision(2) << GPA;
        }
};

int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}