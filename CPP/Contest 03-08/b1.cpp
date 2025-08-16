#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

// Hàm ki?m tra nguyên t? t?i uu
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int sqrtN = sqrt(n);
    for (int i = 5; i <= sqrtN; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

// Sinh s? t? d ch? s? tang/gi?m d?n
void generateMonotonicNumbers(int d, set<int>& results) {
    vector<int> digits;

    // Tang d?n
    for (int i = 1; i <= 9; ++i) digits.push_back(i);
    vector<bool> select(digits.size(), false);
    fill(select.end() - d, select.end(), true);
    do {
        vector<int> temp;
        for (int i = 0; i < digits.size(); ++i)
            if (select[i]) temp.push_back(digits[i]);
        if (is_sorted(temp.begin(), temp.end())) {
            int num = 0;
            for (int x : temp) num = num * 10 + x;
            results.insert(num);
        }
    } while (next_permutation(select.begin(), select.end()));

    // Gi?m d?n
    digits.clear();
    for (int i = 9; i >= 0; --i) digits.push_back(i); // 0 du?c cho phép ? gi?a
    fill(select.begin(), select.end(), false);
    select.resize(digits.size(), false);
    fill(select.end() - d, select.end(), true);
    do {
        vector<int> temp;
        for (int i = 0; i < digits.size(); ++i)
            if (select[i]) temp.push_back(digits[i]);
        if (is_sorted(temp.begin(), temp.end(), greater<int>()) && temp[0] != 0) {
            int num = 0;
            for (int x : temp) num = num * 10 + x;
            results.insert(num);
        }
    } while (next_permutation(select.begin(), select.end()));
}

int countPrimeMonotonicNumbers(int d) {
    set<int> nums;
    generateMonotonicNumbers(d, nums);

    int count = 0;
    for (int x : nums) {
        if (isPrime(x)) ++count;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int d;
        cin >> d;
        cout << countPrimeMonotonicNumbers(d) << endl;
    }
    return 0;
}



//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		int n;
//		cin>>n;
//		int a[]={5,20,38,50,38,20,8,5,0};
//		cout<<a[n-1]<<endl;
//	}
//}
