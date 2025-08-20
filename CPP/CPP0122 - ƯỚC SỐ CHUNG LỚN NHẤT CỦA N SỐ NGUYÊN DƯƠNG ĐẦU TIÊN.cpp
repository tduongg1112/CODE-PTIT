// https://code.ptit.edu.vn/student/question/CPP0122
// ƯỚC SỐ CHUNG LỚN NHẤT CỦA N SỐ NGUYÊN DƯƠNG ĐẦU TIÊN

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    while (b > 0) {
        ll x = a % b;
        a = b;
        b = x;
    }
    return a;
}

void solve(){
    ll n;
    cin >> n;
    ll r = 1;
    for (ll i = 1; i <= n; ++i) {
        ll g = gcd(r, i);
        r = r * i / g;
    }
    cout << r << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}