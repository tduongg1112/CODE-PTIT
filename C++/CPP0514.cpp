// https://code.ptit.edu.vn/student/question/CPP0514
// DANH SÁCH SINH VIÊN - 2

#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string id, name, lop, dob;
    double gpa;
};

string msv(int i){
    string s = to_string(i);
    while(s.length() < 3){
        s = '0' + s;
    }
    return "B20DCCN" + s;
}

string ChuanHoaNgay(string s){
    if (s[1] == '/') s.insert(0, "0");
    if (s[4] == '/') s.insert(3, "0"); 
    return s;
}

string ChuanHoaTen(string s){
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

void nhap (SinhVien ds[], int N){
    for (int i = 0; i < N; i++){
        cin.ignore(); 
        ds[i].id = msv(i + 1);
        getline(cin, ds[i].name);
        getline(cin, ds[i].lop);
        getline(cin, ds[i].dob);
        cin >> ds[i].gpa;
    } 
}

void in (SinhVien ds[], int N){
    for (int i = 0; i < N; i++){
        cout << ds[i].id << " " << ChuanHoaTen(ds[i].name) << " " << ds[i].lop << " " << ChuanHoaNgay(ds[i].dob) << " ";
        cout << fixed << setprecision(2) << ds[i].gpa << endl;
    }
}


int main(){
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}