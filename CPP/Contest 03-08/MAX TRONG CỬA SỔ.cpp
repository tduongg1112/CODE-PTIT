#include <bits/stdc++.h>
using namespace std;

void solveTest(int n, int k, vector<int>& A) {
    deque<int> dq; 
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && A[dq.back()] <= A[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            printf("%d ", A[dq.front()]);
        }
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        solveTest(n, k, A);
    }
    return 0;
}