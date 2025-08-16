// https://code.ptit.edu.vn/student/question/CPP0801
// SAO CHÉP TỆP TIN

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("PTIT.in");      // mở file PTIT.in để đọc
    ofstream out("PTIT.out");    // mở file PTIT.out để ghi

    string line;
    while (getline(in, line)) {  // đọc từng dòng
        out << line << endl;     // ghi ra dòng tương ứng
    }

    in.close();
    out.close();

    return 0;
}
