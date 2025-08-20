// https://code.ptit.edu.vn/student/question/CPP0106
// SỐ THUẬN NGHỊCH

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void TestCase()
{
    string s;
    cin >> s;
    string x = s;
    reverse(x.begin(), x.end());
    x == s ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        TestCase();
    return 0;
}

// int t; cin >> t;
// while (t--){
//     long long n;
//     cin >> n; // 123
//     long long m = n;
//     long long rev = 0;
//     while(n){
//         int cs = n%10; //1
//         n = n/10; //0
//         rev = rev*10 + cs; //32*10+1 = 321
//     }
//     if (rev == m){
//         cout << "YES";
//     } else {
//         cout << "NO";
//     }
//     cout << endl;
// }