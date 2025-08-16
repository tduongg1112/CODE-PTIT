#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i % k;
    }

    if (sum == k)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
