#include<bits/stdc++.h>
using namespace std;
#define ll long long
//step1: solve using recursion --->TC:O(2^(n+m))
//step2: Optimise the recursion using dp--->TC:O(n*m)
int lcs(int i,int j,vector<int>&a,vector<int>&b,vector<vector<int>>&dp){
    if(i<0 || j<0){
        return 0;
    } 
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(a[i]==b[j]){
        return dp[i][j]=1+lcs(i-1,j-1,a,b,dp);
    }
    else{
        return dp[i][j]=max(lcs(i,j-1,a,b,dp),lcs(i-1,j,a,b,dp));
    }
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans=lcs(n-1,m-1,a,b,dp);
    cout<<ans<<endl;
    vector<int>sq;
    int i=n-1,j=m-1;
    while(i>=0 && j>=0){
        if(a[i]==b[j]){
            sq.push_back(a[i]);
            i--;
            j--;
        }
        else if(i>0 && dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(sq.begin(),sq.end());
    for(int x:sq){
        cout<<x<<" ";
    }
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}