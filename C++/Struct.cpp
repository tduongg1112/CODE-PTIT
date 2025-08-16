#include <bits/stdc++.h>
using namespace std;

struct NhanVien {
    string maNV;
    string hoTen;
    float heSoLuong;
    int luongCoBan;
    int phuCap;
};

void Nhap(NhanVien nv){
    cin >> nv.maNV;
    cin.ignore();
    getline(cin, nv.hoTen);
    cin >> nv.heSoLuong >> nv.luongCoBan >> nv.phuCap;
}

int tinhTongLuong(NhanVien nv) {
    return nv.luongCoBan * nv.heSoLuong + nv.phuCap;
}

int main() {
    NhanVien nv;
    Nhap(nv);
    tinhTongLuong(nv);
    return 0;
}
