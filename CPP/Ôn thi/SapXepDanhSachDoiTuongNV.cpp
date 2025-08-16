// https://code.ptit.edu.vn/student/question/CPP0615
// SẮP XẾP DANH SÁCH ĐỐI TƯỢNG NHÂN VIÊN

#include <bits/stdc++.h>
using namespace std;

static int cnt = 1; 

class NhanVien {
    public:
        string id, name, gender, dob, address, tax, signedDay;
        int d, m, y;

    string mnv (int i){
        string s = to_string(i);
        if (s.length() == 1) s = "0000" + s;
        else s = "000" + s;
        return s;
    }

    string ChuanHoaNgay (string s){
        if (s[1] == '/') s.insert(0, "0");
        if (s[4] == '/') s.insert(3, "0");
        return s;
    }

    friend istream &operator >> (istream &is, NhanVien &a){
        static bool first = true;
        while (first){
            is.ignore();
            first = false;
        }
        // scanf("\n");
        getline(is, a.name);
        getline(is, a.gender);
        getline(is, a.dob);
        getline(is, a.address);
        getline(is, a.tax);
        getline(is, a.signedDay);
        
        a.id = a.mnv(cnt++);
        a.dob = a.ChuanHoaNgay(a.dob);
        a.signedDay = a.ChuanHoaNgay(a.signedDay);
        
        a.m = stoi(a.dob.substr(0, 2));
        a.d = stoi(a.dob.substr(3, 2));
        a.y = stoi(a.dob.substr(6));

        return is;
    }

    friend ostream &operator << (ostream &os, NhanVien a){
        os << a.id << " " << a.name << " " << a.gender << " " << a.dob << " " << a.address << " " << a.tax << " " << a.signedDay << endl; 
        return os;
    }
};

bool cmp (NhanVien a, NhanVien b){
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

void sapxep (NhanVien ds[], int N){
    sort (ds, ds + N, cmp);
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}