#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int day, month, year;
    long long dateValue; 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<Person> people(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> people[i].name;
        string date;
        cin >> date;
        sscanf(date.c_str(), "%d/%d/%d", &people[i].day, &people[i].month, &people[i].year);
        people[i].dateValue = people[i].year * 10000LL + people[i].month * 100 + people[i].day;
    }
    
    int youngest = 0, oldest = 0;
    for (int i = 1; i < N; ++i) {
        if (people[i].dateValue > people[youngest].dateValue) {
            youngest = i;
        }
        if (people[i].dateValue < people[oldest].dateValue) {
            oldest = i;
        }
    }
    cout << people[youngest].name << endl;
    cout << people[oldest].name << endl;
    
    return 0;
}
