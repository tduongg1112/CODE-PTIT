// https://code.ptit.edu.vn/student/question/CPP0332
// ĐỊA CHỈ EMAIL - 1

#include <bits/stdc++.h>
using namespace std;

void email(){
    string s;
    getline(cin, s);
    stringstream q(s);
    string word;
    string res;
    while (q >> word){
        res += tolower(word[0]);
    } // res = nva;

    for (int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    } // word = an;
    cout << word;

    for (int i = 0; i < res.length() - 1; i++){
        cout << res[i];
    }
    cout << "@ptit.edu.vn";
}

int main (){
    email();
    return 0;
}