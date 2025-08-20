#include <bits/stdc++.h>
using namespace std;

int findMaxDifference(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return -1;

    int min_val = arr[0];
    int max_diff = -1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > min_val)
            max_diff = max(max_diff, arr[i] - min_val);
        min_val = min(min_val, arr[i]);
    }

    return max_diff;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        cout << findMaxDifference(A) << endl;
    }
    return 0;
}

