// https://code.ptit.edu.vn/student/question/CPP0801
// SAO CHÉP TỆP TIN

#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("PTIT.in");
    ofstream out("PTIT.out");

    string line;
    while (getline(in, line)){
        out << line << endl;
    }

    in.close();
    out.close();
}