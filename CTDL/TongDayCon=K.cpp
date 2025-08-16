#include <bits/stdc++.h>
using namespace std;

    int n, k;
    vector<int> a;              //Chọn hoặc ko chọn
    vector<int> b;              //Phần tử đầu vào
    vector<vector<int>> res;    //Chứa các dãy con thỏa mãn

void pb(){                      //Hàm kiểm tra dãy con
    int sum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            sum += b[i];
        }
    }
    if (sum == k){
        res.push_back(a);
    }
}

void backtrack(int k){          //Hàm đệ quy quay lui
    for (int i = 0; i <= 1; i++){
        a[k] = i;
        if (k == n - 1){
            pb();
        }
        else
            backtrack(k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n, 0);
    b.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    backtrack(0);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            if (res[i][j] == 1)
                cout << b[j] << ' ';
        cout << endl;
    }
    cout << res.size();
}