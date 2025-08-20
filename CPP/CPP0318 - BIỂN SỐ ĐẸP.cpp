// https://code.ptit.edu.vn/student/question/CPP0318
// BIỂN SỐ ĐẸP

#include <bits/stdc++.h>
using namespace std;

bool ascending (string s){
    for (int i = 1; i < s.length(); i++){
        if (s[i] <= s[i - 1]){
            return 0;
        }
    }
    return 1;
}

bool descending (string s){
    for (int i = 1; i < s.length(); i++){
        if (s[i] >= s[i - 1]){
            return 0;
        }
    }
    return 1;
}

bool equal (string s){
    for (int i = 1; i < s.length(); i++){
        if (s[i] != s[i - 1]){
            return 0;
        }
    }
    return 1;
}

bool beautiful (string s){
    if (s[0] == s[1] && s[1] == s[2] && s[3] == s[4]){
        return 1;
    }
    return 0;
}

bool lucky (string s){
    for (int i = 0; i < s.length(); i++){
        if (s[i] != '6' && s[i] != '8'){
            return 0;
        }
    }
    return 1;
}

void testcase(){
    string s; cin >> s;
    s.erase(0, 5);
    s.erase(3, 1);
    if (ascending(s) || equal(s) || beautiful(s) || lucky(s)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        testcase();
    }
}