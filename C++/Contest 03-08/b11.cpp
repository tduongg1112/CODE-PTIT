//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		string a;
//		cin>>a;
//		int n=a.size(),s=0,b[26]={},c[26]={},mim=1e6,d=0,l=0,r=-1;
//	    for(int i=0;i<n;i++){
//	        if(b[a[i]-'a']==0){
//	            b[a[i]-'a']=1;
//	            s++;
//	        }
//	    }
//	    for(int i=0;i<n;i++){
//	        c[a[i]-'a']++;
//	        if(c[a[i]-'a']==1) d++;
//	        if(d==s){
//	            while(c[a[l]-'a']>1){
//	                if(c[a[l]-'a']>1) c[a[l]-'a']--;
//	                l++;
//	            }
//	            int lw=i-l+1;
//	            if(mim>lw){
//	                mim=lw;
//	                r=l;
//	            }
//	        }
//	    }
//	    cout<<mim<<endl;
//	}
//}


#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

int minWindowLength(const string& s) {
    unordered_set<char> uniqueChars(s.begin(), s.end());
    int required = uniqueChars.size();

    unordered_map<char, int> windowCount;
    int left = 0, formed = 0, minLen = INT_MAX;

    for (int right = 0; right < s.size(); ++right) {
        char c = s[right];
        windowCount[c]++;
        if (windowCount[c] == 1) formed++; // d?m ký t? m?i

        while (formed == required) {
            minLen = min(minLen, right - left + 1);
            windowCount[s[left]]--;
            if (windowCount[s[left]] == 0) formed--;
            left++;
        }
    }

    return minLen;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // b? dòng newline

    while (T--) {
        string s;
        getline(cin, s);
        cout << minWindowLength(s) << '\n';
    }

    return 0;
}

