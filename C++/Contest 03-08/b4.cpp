#include <iostream>
#include <cmath>
using namespace std;

// H�m ki?m tra s? nguy�n t?
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

// H�m t�nh t?ng ch? s?
int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// H�m ki?m tra s? Smith
bool isSmith(int n) {
    if (isPrime(n)) return false;

    int sumDigits = digitSum(n);
    int primeFactorDigitSum = 0;
    int temp = n;

    for (int i = 2; i * i <= temp; ++i) {
        while (n % i == 0) {
            primeFactorDigitSum += digitSum(i);
            n /= i;
        }
    }

    // N?u c�n 1 th?a s? nguy�n t? l?n hon vn
    if (n > 1)
        primeFactorDigitSum += digitSum(n);

    return sumDigits == primeFactorDigitSum;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (isSmith(N) ? "YES" : "NO") << endl;
    }
    return 0;
}

