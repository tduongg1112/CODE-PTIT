#include <bits/stdc++.h>
using namespace std;

const int MAX_M = 105;
const int MAX_N = 105;

long long dp[MAX_M][MAX_N];

void solve(int M, int N, string S) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; 
    
    for (int i = 0; i < M; ++i) {
        for (int mod = 0; mod < N; ++mod) {
            if (dp[i][mod] == 0) continue;
            dp[i + 1][mod] += dp[i][mod];
            int digit = S[i] - '0';
            int new_mod = (mod * 10 + digit) % N;
            dp[i + 1][new_mod] += dp[i][mod];
        }
    }
        cout << dp[M][0] - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int M, N;
        string S;
        cin >> M >> N >> S;
        solve(M, N, S);
    }
    
    return 0;
}
