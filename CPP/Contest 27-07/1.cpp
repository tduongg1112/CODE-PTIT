#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("DATA.in");
    int count[1000] = {0}; 
    int x;
    while (file >> x) {
        if (x >= 0 && x < 1000) {
            count[x]++;
        }
    }

    for (int i = 0; i < 1000; ++i) {
        if (count[i] > 0) {
            cout << i << " " << count[i] << endl;
        }
    }

    return 0;
}

