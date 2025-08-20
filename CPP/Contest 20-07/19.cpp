#include <bits/stdc++.h>
using namespace std;

// Hàm chuẩn hóa từ: chữ cái đầu viết hoa, còn lại thường
string capitalize(string word) {
    if (word.empty()) return "";
    for (char &c : word) c = tolower(c);
    word[0] = toupper(word[0]);
    return word;
}

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<string> parts;
    string word;

    while (ss >> word) {
        parts.push_back(word);
    }

    if (parts.empty()) return 0;

    string last = parts.back(); // Tên
    parts.pop_back();           // Phần còn lại: họ và tên đệm

    // Chuẩn hóa họ và tên đệm
    for (int i = 0; i < parts.size(); i++) {
        parts[i] = capitalize(parts[i]);
    }

    // In kết quả
    for (int i = 0; i < parts.size(); i++) {
        cout << parts[i];
        if (i < parts.size() - 1) cout << " ";
    }

    if (!parts.empty()) cout << ", ";
    else cout << ",";

    // In TÊN in hoa toàn bộ
    for (char &c : last) cout << (char)toupper(c);
    cout << endl;

    return 0;
}