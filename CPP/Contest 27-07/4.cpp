#include <bits/stdc++.h>
using namespace std;

class IntSet {
private:
    set<int> s;

public:
    IntSet(int a[], int n) {
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0 && a[i] < 1000)
                s.insert(a[i]);
        }
    }

    IntSet intersection(const IntSet& other) const {
        IntSet result({}, 0);
        for (int x : s) {
            if (other.s.count(x)) {
                result.s.insert(x);
            }
        }
        return result;
    }

    void print() const {
        for (int x : s) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    ifstream file("DATA.in");
    int n, m;
    file >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; ++i) file >> a[i];
    for (int i = 0; i < m; ++i) file >> b[i];

    IntSet setA(a, n);
    IntSet setB(b, m);
    IntSet result = setA.intersection(setB);

    result.print();

    return 0;
}

