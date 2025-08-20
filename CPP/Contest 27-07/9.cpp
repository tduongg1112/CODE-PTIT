#include <bits/stdc++.h>
using namespace std;

void processTestCase(vector<int>& A, vector<int>& B) {
    set<int> setA(A.begin(), A.end());
    set<int> setB(B.begin(), B.end());

    set<int> unionSet = setA;
    for (int x : setB) {
        unionSet.insert(x);
    }

    vector<int> intersection;
    for (int x : setA) {
        if (setB.find(x) != setB.end()) {
            intersection.push_back(x);
        }
    }

    for (int x : unionSet) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : intersection) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        vector<int> B(m);
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }
        
        processTestCase(A, B);
    }
    return 0;
}
