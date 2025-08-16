#include <bits/stdc++.h>
using namespace std;

bool revert (string s){
    int n = s.size();
    for (int i = 0; i <= n/2; i++){
        if (s[i] != s[n - i - 1]){
            return 0;
        }
    }
    return 1;
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        s += '0';
    }

    while(1){
        if (revert(s)){
            for (int i = 0; i < s.size(); i++){
                cout << s[i] << " ";
            }
            cout << endl;
        }    
        
        int ok = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == '0'){
                s[i] = '1';
                ok = 1;
                for (int j = i + 1; j < n; j++){
                    s[j] = '0';
                }
                break;
            }
        }
        if (ok == 0){
            break;
        }
    }
}