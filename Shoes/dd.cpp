#include <bits/stdc++.h>
#define int long long
using namespace std;
 
string s;
int ans, ans1;
signed main() {
    int n; cin >> n; 
    cin>>s>>s;
    int cnt=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='G') {
            ans+=abs(2*cnt-i); ans1+=abs(2*cnt+1-i);
            cnt++;
        }
    }
    cout<<min(ans, ans1);
}