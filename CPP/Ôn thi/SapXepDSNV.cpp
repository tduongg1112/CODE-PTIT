// https://code.ptit.edu.vn/student/question/CPP0518
// SẮP XẾP DANH SÁCH NHÂN VIÊN

#include <bits/stdc++.h>
using namespace std;

static int stt = 1;

struct NhanVien {
    string id, name, gender, dob, address, tax, signedDay;
    int d, m, y;
};

string mnv(int i){
    string r = to_string(i);
    if (i < 10) r = "0000" + r;
    else r = "000" + r;
    return r;
}

string ChuanHoaNgay(string s){
    if (s[1] == '/') s.insert(0, "0");
    if (s[4] == '/') s.insert(3, "0");
    return s;
}

bool cmp (NhanVien a, NhanVien b){
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

void sapxep(NhanVien ds[], int N){
    sort (ds, ds + N, cmp);
}

void nhap(NhanVien &a){
    static bool first = true;
    while(first){
        cin.ignore();
        first = false;
    }

    a.id = mnv(stt); stt++;
    getline(cin, a.name);
    getline(cin, a.gender);
    getline(cin, a.dob);
    getline(cin, a.address);
    getline(cin, a.tax);
    getline(cin, a.signedDay);

    string s = ChuanHoaNgay(a.dob);
    a.m = stoi(s.substr(0,2));
    a.d = stoi(s.substr(3,2));
    a.y = stoi(s.substr(6));
}

void inds(NhanVien ds[], int N){
    for (int i = 0; i < N; i++){
        cout << ds[i].id << " " << ds[i].name << " " << ds[i].gender << " " << ChuanHoaNgay(ds[i].dob) << " " << ds[i].address << " " << ds[i].tax << " " << ChuanHoaNgay(ds[i].signedDay) << endl;
    }
}

int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}