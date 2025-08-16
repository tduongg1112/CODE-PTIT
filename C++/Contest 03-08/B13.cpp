#include <iostream>
#include <vector>
#include <algorithm>
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
        bool takeMax = true;  // true: l?y ph?n t? l?n nh?t, false: l?y ph?n t? nh? nh?t

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

        // In k?t qu?
        for (int i = 0; i < (int)result.size(); i++) {
            cout << result[i];
            if (i != (int)result.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

