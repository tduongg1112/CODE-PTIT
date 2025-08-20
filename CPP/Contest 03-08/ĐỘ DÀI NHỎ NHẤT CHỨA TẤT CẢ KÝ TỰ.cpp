#include <bits/stdc++.h>
using namespace std;

int minWindowLength(const string& s) {
    unordered_set<char> uniqueChars(s.begin(), s.end());
    int required = uniqueChars.size();

    unordered_map<char, int> windowCount;
    int left = 0, formed = 0, minLen = INT_MAX;

    for (int right = 0; right < s.size(); ++right) {
        char c = s[right];
        windowCount[c]++;
        if (windowCount[c] == 1) formed++; 

        while (formed == required) {
            minLen = min(minLen, right - left + 1);
            windowCount[s[left]]--;
            if (windowCount[s[left]] == 0) formed--;
            left++;
        }
    }

    return minLen;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string s;
        getline(cin, s);
        cout << minWindowLength(s) << '\n';
    }
    return 0;
}