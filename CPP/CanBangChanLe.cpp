#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    int e = 0, o = 0;
    while (n > 0)
    {
        int x = n % 10;
        if (x % 2 == 0)
            e++;
        else
            o++;
        n /= 10;
    }
    if (e == 0){
        return true;
    } else return false;
}

int main()
{
    int n;
    cin >> n;
    int l = pow(10, n - 1);
    int r = pow(10, n) - 1;
    int cnt = 0;
    for (int i = l; i <= r; ++i)
    {
        if (check(i))
        {
            cout << i << " ";
            cnt++;
            if (cnt == 10)
                cout << endl;
            cnt %= 10;
        }
    }
    return 0;
}