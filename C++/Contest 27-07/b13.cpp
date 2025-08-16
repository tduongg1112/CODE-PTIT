#include <bits/stdc++.h>
using namespace std;

struct PhanSo {
    long long tu, mau;
};

long long gcd(long long a, long long b) {
    return __gcd(abs(a), abs(b));
}

void rutGon(PhanSo &p) {
    long long g = gcd(p.tu, p.mau);
    p.tu /= g;
    p.mau /= g;
    if (p.mau < 0) { 
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
}

PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu * b.mau + b.tu * a.mau;
    res.mau = a.mau * b.mau;
    rutGon(res);
    return res;
}

PhanSo nhan(PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu * b.tu;
    res.mau = a.mau * b.mau;
    rutGon(res);
    return res;
}

PhanSo binhPhuong(PhanSo p) {
    PhanSo res;
    res.tu = p.tu * p.tu;
    res.mau = p.mau * p.mau;
    rutGon(res);
    return res;
}

void in(PhanSo p) {
    cout << p.tu << "/" << p.mau;
}

void process(PhanSo A, PhanSo B) {
    PhanSo C = binhPhuong(cong(A, B));
    PhanSo D = nhan(nhan(A, B), C);
    in(C);
    cout << " ";
    in(D);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        PhanSo A;
        PhanSo B;
        cin >> A.tu >> A.mau >> B.tu >> B.mau;
        process(A, B);
    }
    return 0;
}
