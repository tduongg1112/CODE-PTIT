// https://code.ptit.edu.vn/student/question/CPP0512
// PHÉP TOÁN VỚI PHÂN SỐ

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct PhanSo {
    ll tu, mau;
};

ll gcd(ll a, ll b){
    while (b > 0){
        ll x = a % b;
        a = b;
        b = x;
    }
    return a;
}

void rutgon(PhanSo &x){
    ll g = gcd(x.tu, x.mau);
    x.tu /= g;
    x.mau /= g;
}

PhanSo sum (PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu * b.mau + a.mau * b.tu;
    c.mau = a.mau * b.mau;
    rutgon(c);
    return c;
}

PhanSo mul (PhanSo a, PhanSo b){
    PhanSo d;
    d.tu = a.tu * b.tu;
    d.mau = a.mau * b.mau;
    rutgon(d);
    return d;
}

void process (PhanSo a, PhanSo b){
    PhanSo c = mul(sum(a, b), sum(a, b));
    PhanSo d = mul(mul(a, b), c);
    cout << c.tu << "/" << c.mau << " " << d.tu << "/" << d.mau << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}