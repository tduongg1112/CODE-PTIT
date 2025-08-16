#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                                  // số bộ test
    if (!(cin >> T)) return 0;
    while (T--) {
        int M, N;                           // số hệ số P và Q
        cin >> M >> N;

        vector<long long> P(M), Q(N);
        for (long long &x : P) cin >> x;
        for (long long &x : Q) cin >> x;

        vector<long long> R(M + N - 1, 0);  // kết quả

        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                R[i + j] += P[i] * Q[j];

        // in ra trên một dòng
        for (size_t k = 0; k < R.size(); ++k) {
            if (k) cout << ' ';
            cout << R[k];
        }
        cout << '\n';
    }
    return 0;
}
