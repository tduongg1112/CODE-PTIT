#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

bool isSphenic(int n) {
    int count = 0;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0 && isPrime(i)) {
            int times = 0;
            while (n % i == 0) {
                ++times;
                n /= i;
            }
            if (times > 1) return false; 
            ++count;
        }
    }

    if (n > 1) {
        if (!isPrime(n)) return false;
        ++count;
    }

    return count == 3;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (isSphenic(N) ? 1 : 0) << endl;
    }
    return 0;
}