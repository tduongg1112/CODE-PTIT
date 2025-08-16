#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct NhanVien {
    string maNV, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKyHD;
};

void nhap(NhanVien &nv, int dem) {
    nv.maNV = string(5 - to_string(dem).length(), '0') + to_string(dem);
    
    if (dem == 1) cin.ignore();
    
    getline(cin, nv.hoTen);
    getline(cin, nv.gioiTinh);
    getline(cin, nv.ngaySinh);
    getline(cin, nv.diaChi);
    getline(cin, nv.maSoThue);
    getline(cin, nv.ngayKyHD);
}

void inds(NhanVien ds[], int N) {
    for (int i = 0; i < N; i++) {
        cout << ds[i].maNV << " " 
             << ds[i].hoTen << " "
             << ds[i].gioiTinh << " "
             << ds[i].ngaySinh << " "
             << ds[i].diaChi << " "
             << ds[i].maSoThue << " "
             << ds[i].ngayKyHD << endl;
    }
}

int main() {
    struct NhanVien ds[50];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) nhap(ds[i], i + 1); 
    inds(ds, N);
    return 0;
}
