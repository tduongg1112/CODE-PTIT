// https://code.ptit.edu.vn/student/question/CPP0351
// CHUẨN HÓA HỌ TÊN

#include <bits/stdc++.h>
using namespace std;

void standard(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vector<string> v;

    // Tách từng từ và chuẩn hóa từng từ rồi lưu vào vector
    while (ss >> word) {
        v.push_back(word);
    }

    // In các từ trừ từ cuối cùng (họ và tên đệm)
    for (int i = 0; i < v.size() - 1; i++) {
        string &w = v[i];
        cout << (char)toupper(w[0]);
        for (int j = 1; j < w.size(); j++) {
            cout << (char)tolower(w[j]);
        }
        cout << " ";
    }

    cout << ", ";

    // In từ cuối cùng viết hoa toàn bộ (tên)
    string last = v.back();
    for (char c : last) {
        cout << (char)toupper(c);
    }
}

int main (){
    standard();
}
