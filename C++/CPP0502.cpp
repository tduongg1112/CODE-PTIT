// https://code.ptit.edu.vn/student/question/CPP0502
// CẤU TRÚC THÍ SINH

#include <bits/stdc++.h>
using namespace std;

struct ThiSinh{
    string name;
    string dob;
    double mark1, mark2, mark3, sum;
};

void nhap(ThiSinh &x){
    getline(cin, x.name);
    getline(cin, x.dob);
    cin >> x.mark1 >> x.mark2 >> x.mark3;
    x.sum = x.mark1 + x.mark2 + x.mark3;
}

void in(ThiSinh x){
    cout << x.name << " " << x.dob << " ";
    cout << fixed << setprecision(1) << x.sum << endl;
}

int main(){
    struct ThiSinh A;
    nhap(A);
    in(A);
    return 0;
}