#include <iostream>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

set<string> getUniqueWords(const string& line) {
    set<string> wordSet;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        wordSet.insert(word);
    }
    return wordSet;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        set<string> set1 = getUniqueWords(s1);
        set<string> set2 = getUniqueWords(s2);

        vector<string> result;
        for (const string& word : set1) {
            if (set2.find(word) == set2.end()) {
                result.push_back(word);
            }
        }

        for (const string& word : result) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

