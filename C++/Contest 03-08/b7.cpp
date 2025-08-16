#include <bits/stdc++.h>
using namespace std;

void solveTest(int n, int k, vector<int>& A) {
    deque<int> dq; // luu ch? s?
    for (int i = 0; i < n; ++i) {
        // Xóa nh?ng ph?n t? nh? hon A[i] ? cu?i deque
        while (!dq.empty() && A[dq.back()] <= A[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Lo?i b? ph?n t? không n?m trong c?a s? size k
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        // B?t d?u t? i >= k - 1 m?i in ra k?t qu?
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

