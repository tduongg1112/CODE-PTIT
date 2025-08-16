#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void processTestCase(vector<int>& A, vector<int>& B) {
    // Create sets for unique elements
    set<int> setA(A.begin(), A.end());
    set<int> setB(B.begin(), B.end());

    // Union
    set<int> unionSet = setA;
    for (int x : setB) {
        unionSet.insert(x);
    }

    // Intersection
    vector<int> intersection;
    for (int x : setA) {
        if (setB.find(x) != setB.end()) {
            intersection.push_back(x);
        }
    }

    // Output union
    for (int x : unionSet) {
        cout << x << " ";
    }
    cout << endl;

    // Output intersection
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
        
        // Read array A
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        // Read array B
        vector<int> B(m);
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }
        
        processTestCase(A, B);
    }
    return 0;
}
