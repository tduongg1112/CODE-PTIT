#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string maSV, hoTen, lop, ngaySinh;
    float GPA;
};

string chuanHoaTen(string s) {
    stringstream ss(s);
    string res = "", word;
    while (ss >> word) {
        for (char &c : word) c = tolower(c);
        word[0] = toupper(word[0]);
        res += word + " ";
    }
    res.pop_back();
    return res;
}

string chuanHoaNgay(string s) {
    string day, month, year;
    stringstream ss(s);
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year);
    if (day.size() == 1) day = "0" + day;
    if (month.size() == 1) month = "0" + month;
    return day + "/" + month + "/" + year;
}

void nhap(SinhVien ds[], int N) {
    for (int i = 0; i < N; ++i) {
        ds[i].maSV = "B20DCCN" + string(3 - to_string(i + 1).size(), '0') + to_string(i + 1);
        
        cin.ignore();
        getline(cin, ds[i].hoTen);
        ds[i].hoTen = chuanHoaTen(ds[i].hoTen);
        
        getline(cin, ds[i].lop);
        getline(cin, ds[i].ngaySinh);
        ds[i].ngaySinh = chuanHoaNgay(ds[i].ngaySinh);
        cin >> ds[i].GPA;
    }
}

void sapxep(SinhVien ds[], int N) {
    sort(ds, ds + N, [](const SinhVien &a, const SinhVien &b) {
        return a.GPA > b.GPA;
    });
}

void in(SinhVien ds[], int N) {
    for (int i = 0; i < N; ++i) {
        cout << ds[i].maSV << " " << ds[i].hoTen << " " << ds[i].lop << " "
             << ds[i].ngaySinh << " " << fixed << setprecision(2) << ds[i].GPA << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    sapxep(ds, N);
    in(ds, N);
    return 0;
}
