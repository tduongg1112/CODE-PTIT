#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
                sort(A.begin(), A.end());
        
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(A.begin() + i + 1, A.end(), A[i] + k - 1);
            count += distance(A.begin() + i + 1, it);
        }
        
        cout << count << endl;
    }
    
    return 0;
}
