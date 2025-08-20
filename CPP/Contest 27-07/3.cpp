#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

void readFileToSet(const string& filename, set<string>& wordSet) {
    ifstream file(filename);
    string line, word;
    while (getline(file, line)) {
        stringstream ss(line);
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            wordSet.insert(word);
        }
    }
}

int main() {
    set<string> set1, set2;
    
    readFileToSet("DATA1.in", set1);
    readFileToSet("DATA2.in", set2);

    set<string> unionSet = set1;
    unionSet.insert(set2.begin(), set2.end());

    set<string> intersectionSet;
    for (const string& word : set1) {
        if (set2.count(word)) {
            intersectionSet.insert(word);
        }
    }

    for (const string& word : unionSet) {
        cout << word << " ";
    }
    cout << endl;

    for (const string& word : intersectionSet) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

