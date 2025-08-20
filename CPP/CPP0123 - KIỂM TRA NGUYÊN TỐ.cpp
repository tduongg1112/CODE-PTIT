// https://code.ptit.edu.vn/student/question/CPP0123
// KIỂM TRA NGUYÊN TỐ

#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    } 
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (check(n)){
        cout << "YES";
    } else cout << "NO";
}