#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto &x:b){
        cin>>x;
    }
    //dp[c] stores the max pages of the book if the cost is c
    vector<int>dp(x+1,0);
    for(int i=0;i<n;i++){
        for(int c=x;c>=a[i];c--){
            dp[c]=max(dp[c],dp[c-a[i]]+b[i]);
        }
    }
    cout<<dp[x]<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}