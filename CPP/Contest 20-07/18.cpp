#include <bits/stdc++.h>
using namespace std;

int countKDistinctSubstrings(string s, int k) {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        for (int j = i; j < n; j++) {
            freq[s[j]]++;
            if (freq.size() == k)
                count++;
            else if (freq.size() > k)
                break; // không cần xét tiếp
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        int k;
        cin >> s >> k;

        cout << countKDistinctSubstrings(s, k) << endl;
    }
    return 0;
}