#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K, X;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cin >> K >> X;
        
        auto it = lower_bound(A.begin(), A.end(), X);
        int pos = it - A.begin();
        
        int left = pos - 1; 
        int right = pos;   
        if (right < N && A[right] == X) ++right; 
        
        vector<int> result;
        int smaller = 0, larger = 0;
        int half_k = K / 2;
        
        while (result.size() < K) {
            if (smaller < half_k && larger < half_k) {
                if (left >= 0 && (right >= N || X - A[left] <= A[right] - X)) {
                    result.push_back(A[left--]);
                    ++smaller;
                } else if (right < N) {
                    result.push_back(A[right++]);
                    ++larger;
                } else if (left >= 0) {
                    result.push_back(A[left--]);
                    ++smaller;
                }
            } else if (smaller < half_k && left >= 0) {
                result.push_back(A[left--]);
                ++smaller;
            } else if (right < N) {
                result.push_back(A[right++]);
                ++larger;
            } else {
                break; 
            }
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
