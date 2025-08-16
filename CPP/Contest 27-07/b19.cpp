#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    getline(cin, s); 
    stringstream ss(s);
    int num, n = 0, even = 0, odd = 0;
    
    while (ss >> num) {
        n++;
        if (num % 2 == 0) even++;
        else odd++;
    }
        if (n % 2 == 0 && even > odd) {
        cout << "YES\n";
    } else if (n % 2 == 1 && odd > even) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        solve();
    }
    
    return 0;
}
