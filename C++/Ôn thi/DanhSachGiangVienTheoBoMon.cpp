// https://code.ptit.edu.vn/student/question/CPP0626
// DANH SÁCH GIẢNG VIÊN THEO BỘ MÔN

#include <bits/stdc++.h>
using namespace std;

static int cnt = 1;

class GiangVien {
    public:
        string id, name, subject, maMon;

    string mgv (int i){
        string s = to_string(i);
        while (s.length() < 2){
            s = "0" + s;
        }
        return s;
    }

    string getSubject (string s){
        stringstream ss(s);
        string res;
        string word;
        while (ss >> word){
            res += toupper(word[0]);
        }
        return res;
    }

    friend istream &operator >> (istream &is, GiangVien &a){
        scanf("\n");
        getline(is, a.name);
        getline(is, a.subject);

        a.id = "GV" + a.mgv(cnt++);
        a.maMon = a.getSubject(a.subject);
        
        return is;
    }

    friend ostream &operator << (ostream &os, GiangVien &a){
        os << a.id << " " << a.name << " " << a.maMon << endl;
        return os;
    }


};

    string tmp (string s){
        stringstream ss(s);
        string res;
        string word;
        while (ss >> word){
            res += toupper(word[0]);
        }
        return res;
    }

void testcase(GiangVien ds[], int n){
    string s;
    getline(cin, s);
    cout << "DANH SACH GIANG VIEN BO MON " << tmp(s) << ":" << endl;
    for (int i = 0; i < n; i++){
        if (ds[i].maMon == tmp(s)){
            cout << ds[i];
        }
    }
}



int main(){
    int n; cin >> n;
    cin.ignore();
    GiangVien ds[50];
    for (int i = 0; i < n; i++){
        cin >> ds[i];
    }
    int q; cin >> q;
    cin.ignore();
    while (q--){
        testcase(ds, n);
    }
}