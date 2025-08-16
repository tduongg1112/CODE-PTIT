#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y, z;
};

long long det(Point a, Point b, Point c) {
    return a.x * (b.y * c.z - b.z * c.y) -
           a.y * (b.x * c.z - b.z * c.x) +
           a.z * (b.x * c.y - b.y * c.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        Point A, B, C, D;
        cin >> A.x >> A.y >> A.z;
        cin >> B.x >> B.y >> B.z;
        cin >> C.x >> C.y >> C.z;
        cin >> D.x >> D.y >> D.z;
        
        Point AB = {B.x - A.x, B.y - A.y, B.z - A.z};
        Point AC = {C.x - A.x, C.y - A.y, C.z - A.z};
        Point AD = {D.x - A.x, D.y - A.y, D.z - A.z};
        
        long long determinant = det(AB, AC, AD);
        
        if (determinant == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
