#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

string formatSentence(const string& sentence) {
    stringstream ss(sentence);
    string word, result;
    while (ss >> word) {
        for (char &c : word) c = tolower(c);
        result += word + " ";
    }
    if (!result.empty()) {
        result.pop_back();
        result[0] = toupper(result[0]); 
    }
    return result;
}

int main() {
    string line, text;
    while (getline(cin, line)) {
        text += line + " ";
    }

    string current = "";
    vector<string> sentences;
    for (char c : text) {
        if (c == '.' || c == '?' || c == '!') {
            if (!current.empty()) {
                sentences.push_back(current);
                current = "";
            }
        } else {
            current += c;
        }
    }

    for (string& sentence : sentences) {
        string formatted = formatSentence(sentence);
        if (!formatted.empty()) {
            cout << formatted << endl;
        }
    }

    return 0;
}

