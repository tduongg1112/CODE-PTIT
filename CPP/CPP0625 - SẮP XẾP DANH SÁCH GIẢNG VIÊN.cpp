// https://code.ptit.edu.vn/student/question/CPP0625
// SẮP XẾP DANH SÁCH GIẢNG VIÊN

#include <bits/stdc++.h>
using namespace std;

class GiangVien{
    private:
        string id, name, lastname, subject;
    public:
        static int cnt;

        void nhap(){
            getline(cin, name);
            getline(cin, subject);

            cnt++;
            if (cnt < 10){
                id = "GV0" + to_string(cnt); 
            } else {
                id = "GV" + to_string(cnt);
            }
        }

        string standard(string s){
            string word;
            string res = "";
            stringstream ss(s);
            while (ss >> word){
                res += toupper(word[0]);
            }
            return res;
        }

        void in(){
            cout << id << " " << name << " " << standard(subject) << endl;
        }

        string getName(){
            return name;
        }
        string getSubject(){
            return subject;
        }
        string getId(){
            return id;
        }
};

int GiangVien::cnt = 0;

bool cmp(GiangVien a, GiangVien b){
    string x = a.getName();
    string y = b.getName();
    stringstream ss1(x);
    stringstream ss2(y);
    string tmp1, tmp2;
    while (ss1 >> tmp1){}
    while (ss2 >> tmp2){}
    if (tmp1 == tmp2){
        return a.getId() < b.getId();
    } return tmp1 < tmp2;
}

int main(){
    int n; cin >> n;
    cin.ignore();
    GiangVien gv[n];
    for (int i = 0; i < n; i++){
        gv[i].nhap();
    }
    sort(gv, gv + n, cmp);
    for (int i = 0; i < n; i++){
        gv[i].in();
    }
}