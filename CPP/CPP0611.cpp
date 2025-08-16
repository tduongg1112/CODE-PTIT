// https://code.ptit.edu.vn/student/question/CPP0611
// DANH SÁCH ĐỐI TƯỢNG SINH VIÊN - 1

#include <bits/stdc++.h>
using namespace std;

static int cnt = 1;

class SinhVien {
    public:
        string id, name, lop, dob;
        double gpa;

    friend istream &operator >> (istream &is, SinhVien &a){
        is.ignore();
        getline(is, a.name);
        is >> a.lop >> a.dob >> a.gpa;

        // Chuẩn hóa msv
        string s = to_string(cnt++);
        while (s.length() < 3)
            s = '0' + s;
        a.id = "B20DCCN" + s;

        return is;
    }

    string ChuanHoa(string s){
        if (s[1] == '/') s.insert(0, "0");
        if (s[4] == '/') s.insert(3, "0");
        return s;
    }

    friend ostream &operator << (ostream &os, SinhVien a){
        os << a.id << " " << a.name << " " << a.lop << " " << a.ChuanHoa(a.dob) << " ";
        os << fixed << setprecision(2) << a.gpa << endl;
        return os;
    }
};

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> ds[i];
    }
    for(i = 0; i < N; i++){
        cout << ds[i];
    }
    return 0;
}