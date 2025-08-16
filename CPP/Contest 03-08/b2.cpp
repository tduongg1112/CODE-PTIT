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

bool isSphenic(int n) {
    int count = 0;  // d?m s? th?a s? nguy�n t? kh�c nhau

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0 && isPrime(i)) {
            int times = 0;
            while (n % i == 0) {
                ++times;
                n /= i;
            }
            if (times > 1) return false;  // kh�ng du?c l?p l?i th?a s?
            ++count;
        }
    }

    // N?u c�n l?i 1 s? > 1 th� cung l� th?a s? nguy�n t?
    if (n > 1) {
        if (!isPrime(n)) return false;
        ++count;
    }

    return count == 3;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (isSphenic(N) ? 1 : 0) << endl;
    }
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		int n,s=0;
//		cin>>n;
//		for(int i=1;i<sqrt(n);i++){
//			if(n%i==0){
//				if(i%2==0) s++;
//				if((n/i)%2==0) s++;
//			}
//		}
//		int k=sqrt(n);
//		if(k*k==n&&k%2==0) s++;
//		cout<<s<<endl;
//	}
//}

