// https://code.ptit.edu.vn/student/question/CPP0355
// XỬ LÝ VĂN BẢN

#include <bits/stdc++.h>
using namespace std;

string standard (string line){
    stringstream ss(line);
    string word;
    string res;
    while (ss >> word){
        for (int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
        }
        res += word + ' ';
    }
    res[0] = toupper(res[0]);
    return res;
}

void solve(){
    string s; string t;
    int cnt = 0;
    while(getline (cin, s)){
        cnt++;
        if (cnt > 100) break;
        if (s == "@") break;
        t += s + ' ';
    }

    string line = "";
    for (int i = 0; i < t.length(); i++){
        if (t[i] == '.' || t[i] == '!' || t[i] == '?'){
            if (line.length() > 0){
                cout << standard(line) << endl;
                line = "";
            }
        } else {
            line += t[i];
        }
    }
}

int main(){
    solve();
}