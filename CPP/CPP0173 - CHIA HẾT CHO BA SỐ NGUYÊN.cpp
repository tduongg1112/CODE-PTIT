// https://code.ptit.edu.vn/student/question/CPP0173
// CHIA HẾT CHO BA SỐ NGUYÊN

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    while (b > 0){
        ll x = a % b;
        a = b;
        b = x;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

void TestCase(){
    ll x, y, z, n;
    cin >> x >> y >> z >> n;
    ll l = pow(10, n - 1);
    ll r = pow(10, n) - 1;
    ll bc = lcm(lcm(x, y), z);
    if (bc > r)
        cout << "-1\n";
    else if (l % bc == 0)
        cout << l << endl;
    else{
        ll d = l / bc;
        cout << bc * (d + 1) << endl;
    }
}

int main(){
    int T;
    cin >> T;
    while (T--)
        TestCase();
    return 0;
}