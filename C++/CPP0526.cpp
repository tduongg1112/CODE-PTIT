// https://code.ptit.edu.vn/student/question/CPP0526
// TRẺ NHẤT – GIÀ NHẤT

#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name, dob;
    int d, m, y;

    void input(){
        cin.ignore();
        cin >> name;
        cin >> dob;

        d = stoi(dob.substr(0, 2));
        m = stoi(dob.substr(3, 2));
        y = stoi(dob.substr(6));
    }
};

bool cmp (Person a, Person b){
    if (a.y != b.y) return a.y > b.y;
    if (a.m != b.m) return a.m > b.m;
    return a.d > b.d;
}

int main(){
    int n; cin >> n;
    struct Person *ds = new Person[n];
    for (int i = 0; i < n; i++){
        ds[i].input();
    }
    sort (ds, ds + n, cmp);
    cout << ds[0].name << endl << ds[n - 1].name << endl;
}