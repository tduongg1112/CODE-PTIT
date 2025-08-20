// https://code.ptit.edu.vn/student/question/CPP0104
// TÍNH TỔNG GIAI THỪA

#include <bits/stdc++.h>
using namespace std;

long long n;

long long giaithua(long long x){
    long long sum = 0;
    long long tmp = 1;
    for (int i = 1; i <= n; i++){
        tmp = tmp * i;
        sum += tmp;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << giaithua(n) << endl;
}