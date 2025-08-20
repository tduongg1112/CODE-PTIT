// https://code.ptit.edu.vn/student/question/CPP0134
// ƯỚC SỐ NGUYÊN TỐ THỨ K

#include <bits/stdc++.h>
using namespace std;

void prime(){
    int n, k; 
    cin >> n >> k;
    vector <int> v;
    for (int i = 2; i <= sqrt(n); i++){
        while (n % i == 0){
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1){
        v.push_back(n);
    }
    if (k <= v.size()){
        cout << v[k - 1] << endl;
    } else if (k > v.size()){
        cout << -1 << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        prime();
    }
}