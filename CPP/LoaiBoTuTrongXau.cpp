#include <bits/stdc++.h>
using namespace std;

void remove(){
    string s;
    getline (cin, s);
    stringstream ss(s);
    string a; cin >> a;
    string word;

    while (ss >> word){
        if (word == a){
            continue;
        }
        cout << word << ' ';
    }
}

int main(){
    remove();
}