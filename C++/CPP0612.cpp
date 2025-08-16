// https://code.ptit.edu.vn/student/question/CPP0612
// DANH SÁCH ĐỐI TƯỢNG SINH VIÊN - 2

#include <bits/stdc++.h>
using namespace std;

static int cnt = 1;

class SinhVien {
    public:
        string id, name, lop, dob;
        double gpa;

    string msv(int i){
        string s = to_string(i);
        while(s.length() < 3){
            s = '0' + s;
        }
        return s;
    }

    string ChuanHoaNgay (string s){
        if (s[1] == '/') s.insert(0, "0");
        if (s[4] == '/') s.insert(3, "0");
        return s;
    }

    string ChuanHoaTen (string s){
        stringstream ss(s);
        string word;
        string res;
        while (ss >> word){
            res += toupper(word[0]);
            for (int i = 1; i < word.length(); i++){
                res += tolower(word[i]);
            }
            res += " ";
        }
        res.pop_back();
        return res;
    }

    friend istream &operator >> (istream &is, SinhVien &a){
        scanf("\n");
        getline(is, a.name);
        is >> a.lop >> a.dob >> a.gpa;
        a.id = "B20DCCN" + a.msv(cnt++);
        a.name = a.ChuanHoaTen(a.name);
        a.dob = a.ChuanHoaNgay(a.dob);
        return is;
    }

    friend ostream &operator << (ostream &os, SinhVien &a){
        os << a.id << " " << a.name << " " << a.lop << " " << a.dob << " ";
        os << fixed << setprecision(2) << a.gpa << endl;
        return os;
    }
};

bool cmp (SinhVien a, SinhVien b){
    return a.gpa > b.gpa;
}

void sapxep(SinhVien ds[], int N){
    sort(ds, ds + N, cmp);
}

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i = 0; i < N; i++){
        cout << ds[i];
    }
    return 0;
}