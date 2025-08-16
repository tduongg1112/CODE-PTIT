#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++){
            s += 'A';
        }
        while(1){
            cout << s << " ";
            int ok = 0;
            for (int i = n - 1; i >= 0; i--){
                if (s[i] == 'A'){
                    ok = 1;
                    s[i] = 'B';
                    for (int j = i + 1; j < n; j++){
                        s[j] = 'A';
                    }
                    break;
                }
            }
            if (ok == 0){
                break;
            }
        }
        cout << endl;
    }
}