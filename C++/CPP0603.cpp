// https://code.ptit.edu.vn/student/question/CPP0603
// KHAI BÁO LỚP SINH VIÊN - 3

#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    public: 
        string id = "B20DCCN001", name, lop, dob;
        double gpa;
    
    string ChuanHoaNgay (string s){
        if (s[1] == '/') s.insert(0, "0");
        if (s[4] == '/') s.insert(3, "0");
        return s;
    }

    string ChuanHoaTen (string s){
        string word;
        string res;
        stringstream ss(s);
        while (ss >> word){
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.length(); i++){
                word[i] = tolower(word[i]);
        }
        res += word + " ";
        }
        if (!res.empty()) res.pop_back();
        return res;
    }

    friend istream &operator >> (istream &is, SinhVien &a){
        getline(is, a.name);
        is >> a.lop >> a.dob >> a.gpa;
        return is;
    }

    friend ostream &operator << (ostream &os, SinhVien a){
        os << a.id << " " << a.ChuanHoaTen(a.name) << " " << a.lop << " "; 
        os << a.ChuanHoaNgay(a.dob) << " ";
        os << fixed << setprecision(2) << a.gpa;
        return os;
    }
};

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}