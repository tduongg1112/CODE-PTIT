#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Comparator so sánh theo "XY" > "YX"
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<string> arr(n);

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            arr[i] = to_string(x);
        }

        sort(arr.begin(), arr.end(), cmp);

        // N?u t?t c? d?u là '0', in ra "0"
        if (arr[0] == "0") {
            cout << 0 << "\n";
            continue;
        }

        for (const auto& s : arr) cout << s;
        cout << "\n";
    }
    return 0;
}

