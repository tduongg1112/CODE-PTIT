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
    } // đc res = nva;

    for (int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    } // word = an;
    cout << word;

    for (int i = 0; i < res.length() - 1; i++){
        cout << res[i];
    }
    cout << "@stu.ptit.edu.vn";
}

int main (){
    email();
    return 0;
}