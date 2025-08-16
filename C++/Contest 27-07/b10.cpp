#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, X;
        cin >> n >> X;
        
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].first;
            arr[i].second = i; 
        }
                sort(arr.begin(), arr.end(), [X](const pair<int, int>& a, const pair<int, int>& b) {
            int diff_a = abs(X - a.first);
            int diff_b = abs(X - b.first);
            if (diff_a == diff_b) return a.second < b.second;
            return diff_a < diff_b;
        });
        
        for (int i = 0; i < n; ++i) {
            cout << arr[i].first;
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
