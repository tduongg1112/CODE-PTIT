// https://code.ptit.edu.vn/student/question/CPP0722
// DÃY SỐ CATALAN

#include <bits/stdc++.h>
using namespace std;

const int MAX = 5005;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> C(n + 1);
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        C[i] = 0;
        for (int j = 0; j < i; j++) {
            C[i] = (C[i] + C[j] * C[i - 1 - j] % MOD) % MOD;
        }
    }

    long long Sn = 0;
    for (int k = 0; k <= n; k++) {
        Sn = (Sn + C[k] * C[n - k] % MOD) % MOD;
    }

    cout << Sn << endl;
    return 0;
}
