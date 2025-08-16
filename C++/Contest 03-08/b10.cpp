//#include <bits/stdc++.h>
//using namespace std;
//bool check(string a){
//	if(a[5]<a[6]&&a[6]<a[7]&&a[7]<a[9]&&a[9]<a[10]) return 1;
//	if(a[5]==a[6]&&a[6]==a[7]&&a[9]==a[10]) return 1;
//	for(int i=5;i<=10;i++){
//		if(i==8) continue;
//		if(a[i]!='6'&&a[i]!='8') return 0;
//	}
//	return 1;
//}
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		string a;
//		cin>>a;
//		if(check(a)) cout<<"YES"<<endl;
//		else cout<<"NO"<<endl;
//	}
//}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm ki?m tra bi?n s? có d?p không
bool isBeautiful(const string& plate) {
    // Tìm v? trí d?u '-'
    size_t dash_pos = plate.find('-');
    string lastPart = plate.substr(dash_pos + 1); // ph?n sau d?u '-'
    
    // L?y 5 ch? s? và lo?i b? d?u '.'
    string digits = "";
    for (char c : lastPart) {
        if (isdigit(c)) digits += c;
    }

    // N?u không d? 5 ch? s? ? không h?p l?
    if (digits.size() != 5) return false;

    // Chuy?n sang vector s?
    vector<int> d(5);
    for (int i = 0; i < 5; ++i)
        d[i] = digits[i] - '0';

    // 1. Tang ch?t
    bool isIncreasing = true;
    for (int i = 0; i < 4; ++i) {
        if (d[i] >= d[i+1]) {
            isIncreasing = false;
            break;
        }
    }
    if (isIncreasing) return true;

    // 2. 5 s? b?ng nhau
    if (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[3] == d[4]) return true;

    // 3. 3 s? d?u b?ng nhau và 2 s? cu?i b?ng nhau
    if (d[0] == d[1] && d[1] == d[2] && d[3] == d[4]) return true;

    // 4. T?t c? là s? 6 ho?c 8
    bool allLucky = true;
    for (int x : d) {
        if (x != 6 && x != 8) {
            allLucky = false;
            break;
        }
    }
    if (allLucky) return true;

    return false;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // b? dòng newline

    while (T--) {
        string plate;
        getline(cin, plate);

        // X? lý tru?ng h?p d?u g?ch là kí t? d?c bi?t
        for (char& c : plate) {
            if (c == '–') c = '-'; // thay th? dash d?c bi?t b?ng dash chu?n
        }

        if (isBeautiful(plate)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

