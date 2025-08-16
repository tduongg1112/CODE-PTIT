// https://code.ptit.edu.vn/student/question/CPP0333
// CHUẨN HÓA HỌ TÊN

#include <bits/stdc++.h>
using namespace std;

string ChuanHoa(string word){
    word[0] = toupper(word[0]);
    for (int i = 1; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
    return word;
}

void solve(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector <string> v;
    string word;

    while (ss >> word){
        v.push_back(ChuanHoa(word));
    }

    string last = v[v.size() - 1];
    for (char &x : last){
        x = toupper(x);
    }

    string res;
    for (int i = 0; i < v.size() - 1; i++){
        res += v[i] + " ";
    }
    res.pop_back();

    // for (int i = 0; i < n - 1; i++) {
    // cout << words[i];             // In họ + tên đệm
    // if (i != n - 2) cout << " ";  // In dấu cách nếu chưa phải từ cuối
    // }

    cout << res << ", " << last << endl;
}

int main(){
    solve();
}