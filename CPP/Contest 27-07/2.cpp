#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("VANBAN.in");
    set<string> uniqueWords;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            uniqueWords.insert(word);
        }
    }

    for (const string& word : uniqueWords) {
        cout << word << endl;
    }

    return 0;
}

