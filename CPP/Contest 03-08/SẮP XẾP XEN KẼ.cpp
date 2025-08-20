#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        sort(A.begin(), A.end());

        vector<int> result;
        int left = 0, right = n - 1;
        bool takeMax = true;  
        while (left <= right) {
            if (takeMax) {
                result.push_back(A[right]);
                right--;
            } else {
                result.push_back(A[left]);
                left++;
            }
            takeMax = !takeMax;
        }
        for (int i = 0; i < (int)result.size(); i++) {
            cout << result[i];
            if (i != (int)result.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

