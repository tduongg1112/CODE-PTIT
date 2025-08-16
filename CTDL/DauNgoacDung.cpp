#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string open = "([{<";
string close = ")]}>";

bool isMatch(char o, char c){
    for (int i = 0; i < 4; ++i){
        if (open[i] == o && close[i] == c) return true;
    }
    return false;
}

bool isValid(const string& s){
    vector<char> stack;
    for (char c : s){
        if (open.find(c) != string :: npos){
            stack.push_back(c);
        }
        else {
            if (stack.empty() || !isMatch(stack.back(), c))
                return false;
            stack.pop_back();
        }
    } 
    return stack.empty();
}

int countValid(string s, int pos = 0){
    if (pos == s.size()) return isValid(s) ? 1 : 0;
    if (s[pos] != '?') return countValid(s, pos + 1);

    int count = 0;
    for (char c : "()[]{}<>"){
        s[pos] = c;
        count += countValid(s, pos + 1);
    }
    s[pos] = '?';
    return count;
}

int main (){
    string s;
    cin >> s;
    cout << countValid(s) << endl;
    return 0;
}