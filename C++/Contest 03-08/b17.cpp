#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    string lop;
    double diem1, diem2, diem3;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    cin.ignore(); // Ð?c b? newline sau s? N

    vector<SinhVien> ds(N);

    for (int i = 0; i < N; i++) {
        getline(cin, ds[i].maSV);
        getline(cin, ds[i].hoTen);
        getline(cin, ds[i].lop);
        cin >> ds[i].diem1 >> ds[i].diem2 >> ds[i].diem3;
        cin.ignore(); // B? newline cu?i dòng di?m
    }

    // S?p x?p theo h? tên (tang d?n)
    sort(ds.begin(), ds.end(), [](const SinhVien& a, const SinhVien& b) {
        return a.hoTen < b.hoTen;
    });

    cout << fixed << setprecision(1);
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " " 
             << ds[i].maSV << " " 
             << ds[i].hoTen << " "
             << ds[i].lop << " "
             << ds[i].diem1 << " " 
             << ds[i].diem2 << " "
             << ds[i].diem3 << "\n";
    }

    return 0;
}

