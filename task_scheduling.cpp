#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    vector<int>jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=profit.size();
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            a.push_back({profit[i],deadline[i]});
        }
        sort(a.rbegin(),a.rend());
        int maxi=*max_element(deadline.begin(),deadline.end());
        vector<int>hash(maxi+1,-1);
        int cnt=0;
        int prof=0;
        for(int i=0;i<n;i++){
            for(int j=a[i].second;j>=1;j--){
                if(hash[j]==-1){
                    hash[j]=i;
                    cnt++;
                    prof+=a[i].first;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(cnt);
        ans.push_back(prof);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}