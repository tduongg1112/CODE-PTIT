#include <iostream>
#include <string>
using namespace std;

string replaceChar(string s, char from, char to) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == from) s[i] = to;
    }
    return s;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string x1, x2;
        cin >> x1 >> x2;

        string min_x1 = replaceChar(x1, '6', '5');
        string min_x2 = replaceChar(x2, '6', '5');

        string max_x1 = replaceChar(x1, '5', '6');
        string max_x2 = replaceChar(x2, '5', '6');

        // Chuyển thành số và tính tổng
        long long min_sum = stoll(min_x1) + stoll(min_x2);
        long long max_sum = stoll(max_x1) + stoll(max_x2);

        cout << min_sum << " " << max_sum << endl;
    }

    return 0;
}