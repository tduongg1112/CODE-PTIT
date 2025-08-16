// https://code.ptit.edu.vn/student/question/CPP0605
// KHAI BÁO LỚP PHÂN SỐ

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class PhanSo{
    private:
        ll tu;
        ll mau;

    public:
        PhanSo (ll t, ll m){
            tu = t;
            mau = m;
        }
        ll gcd (ll a, ll b){
            while (b != 0){
                ll x = a % b;
                a = b;
                b = x;
            }
            return a;
        }
        void rutgon(){
            ll uc = gcd(tu, mau);
            tu /= uc;
            mau /= uc;
        }
        friend istream &operator >> (istream &is, PhanSo &x){
            is >> x.tu >> x.mau;
            return is;
        }
        friend ostream &operator << (ostream &os, PhanSo &x){
            os << x.tu << "/" << x.mau;
            return os;
        } 
};

int main (){
    PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}