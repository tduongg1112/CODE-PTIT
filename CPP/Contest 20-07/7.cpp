#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
vector<int> minPrime(MAX + 1);

void solve() {
    for (int i = 0; i <= MAX; i++) {
        minPrime[i] = 0;
    }

    minPrime[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (minPrime[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
}

int main() {
    solve();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cout << minPrime[i] << " ";
        }
        cout << endl;
    }
}