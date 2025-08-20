#include <bits/stdc++.h>
using namespace std;

string toUpper(char c) {
    if (c >= 'a' && c <= 'z') return string(1, c - 'a' + 'A');
    return string(1, c);
}

string vietTat(const string& boMon) {
    stringstream ss(boMon);
    string word;
    string res;
    while (ss >> word) {
        res += toupper(word[0]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    cin.ignore();

    struct GiangVien {
        string maGV;
        string hoTen;
        string boMon;
        string boMonVT;
    };

    vector<GiangVien> ds(N);

    for (int i = 0; i < N; i++) {
        getline(cin, ds[i].hoTen);
        getline(cin, ds[i].boMon);
        ds[i].maGV = string("GV") + (i+1 < 10 ? "0" : "") + to_string(i+1);
        ds[i].boMonVT = vietTat(ds[i].boMon);
    }

    int Q; cin >> Q;
    cin.ignore();

    while (Q--) {
        string queryBM;
        getline(cin, queryBM);

        string queryVT = vietTat(queryBM);

        cout << "DANH SACH GIANG VIEN BO MON " << queryVT << ":\n";

        for (const auto& gv : ds) {
            if (gv.boMon == queryBM) {
                cout << gv.maGV << " " << gv.hoTen << " " << gv.boMonVT << "\n";
            }
        }
    }

    return 0;
}

