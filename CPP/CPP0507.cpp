// https://code.ptit.edu.vn/student/question/CPP0507
// TÍNH TỔNG 2 PHÂN 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct PhanSo{
    ll tu, mau;
};

void nhap(PhanSo &p){
    cin >> p.tu >> p.mau;
}

void rutgon(PhanSo &p){
    ll g = __gcd(p.tu, p.mau);
    p.tu /= g;
    p.mau /= g;
}

PhanSo tong(PhanSo &p, PhanSo &q){
    PhanSo t;
    t.tu = p.tu * q.mau + q.tu * p.mau;
    t.mau = q.mau * p.mau;
    rutgon(t);
    return t;
}

void in(PhanSo p){
    cout << p.tu << "/" << p.mau;
}

int main(){
    struct PhanSo p, q;
    nhap(p), nhap(q);
    PhanSo t = tong(p, q);
    in(t);
    return 0;
}