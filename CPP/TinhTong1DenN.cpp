#include <bits/stdc++.h>
using namespace std;

long long sum(long long n){
    return n * (n + 1)/2;
}

int main (){
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        cout << sum(n) << endl;
    }
}