#include <bits/stdc++.h>
using namespace std;

class IntSet {
private:
    vector<int> elements; 
public:
    IntSet() {}

    IntSet(const vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        for (int x : temp) {
            if (elements.empty() || elements.back() != x)
                elements.push_back(x);
        }
    }
    void add(int x) {
        auto it = lower_bound(elements.begin(), elements.end(), x);
        if (it == elements.end() || *it != x) {
            elements.insert(it, x);
        }
    }
    IntSet intersection(const IntSet& other) const {
        IntSet res;
        size_t i = 0, j = 0;
        while (i < elements.size() && j < other.elements.size()) {
            if (elements[i] == other.elements[j]) {
                res.elements.push_back(elements[i]);
                i++; j++;
            } else if (elements[i] < other.elements[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }

    void print() const {
        for (size_t i = 0; i < elements.size(); i++) {
            cout << elements[i];
            if (i != elements.size() - 1) cout << " ";
        }
        cout << "\n";
    }
};

int main() {
    ifstream fin("DATA.in");

    int n, m;
    fin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) fin >> a[i];
    for (int i = 0; i < m; i++) fin >> b[i];

    IntSet A(a);
    IntSet B(b);

    IntSet C = A.intersection(B);
    C.print();

    fin.close();
    return 0;
}

