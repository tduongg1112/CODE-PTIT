// https://code.ptit.edu.vn/student/question/CPP0503
// CẤU TRÚC PHÂN SỐ

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct PhanSo{
    ll x;
    ll y;
};

void nhap(PhanSo &a){
    cin >> a.x >> a.y;
}

void rutgon(PhanSo &a){
    ll g = __gcd(a.x, a.y); // Dùng cho C++ 11 & 14
    a.x /= g;
    a.y /= g;
}

void in(PhanSo a){
    cout << a.x << "/" << a.y << endl;
}

int main(){
    struct PhanSo p;
	nhap(p);
    rutgon(p);
	in(p);
	return 0;
}