#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(string number) {
    int sum = 0;
    for (char c : number) {
        sum += c - '0';
    }
    return sum;
}

bool isLuckyNumber(string number) {
    int sum = sumOfDigits(number);
    
    if (sum == 0) return false;
    
    while (sum >= 10) {
        string temp = to_string(sum);
        sum = sumOfDigits(temp);
    }
    
    return sum == 9;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string n;
        cin >> n;
        cout << (isLuckyNumber(n) ? 1 : 0) << endl;
    }
    return 0;
}
