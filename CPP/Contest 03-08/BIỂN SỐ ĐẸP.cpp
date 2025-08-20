#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(const string& plate) {
    size_t dash_pos = plate.find('-');
    string lastPart = plate.substr(dash_pos + 1); 
    
    string digits = "";
    for (char c : lastPart) {
        if (isdigit(c)) digits += c;
    }

    if (digits.size() != 5) return false;

    vector<int> d(5);
    for (int i = 0; i < 5; ++i)
        d[i] = digits[i] - '0';

    bool isIncreasing = true;
    for (int i = 0; i < 4; ++i) {
        if (d[i] >= d[i+1]) {
            isIncreasing = false;
            break;
        }
    }
    if (isIncreasing) return true;

    if (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[3] == d[4]) return true;

    if (d[0] == d[1] && d[1] == d[2] && d[3] == d[4]) return true;

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
    cin.ignore();

    while (T--) {
        string plate;
        getline(cin, plate);

        for (char& c : plate) {
            if (c == '�') c = '-'; 
        }

        if (isBeautiful(plate)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

