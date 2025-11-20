#include<bits/stdc++.h>
using namespace std;

// Step 1: Standard LCS DP
int lcs(int n, int m, vector<int>& a, vector<int>& b, vector<vector<int>>& dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// Step 2: Print ALL LCS using backtracking
void backtrack(int i, int j, vector<int>& a, vector<int>& b,
               vector<vector<int>>& dp, vector<int>& curr,
               set<vector<int>>& result) {

    if(i == 0 || j == 0){
        vector<int> temp = curr;
        reverse(temp.begin(), temp.end());
        result.insert(temp);
        return;
    }

    if(a[i-1] == b[j-1]) {
        curr.push_back(a[i-1]);
        backtrack(i-1, j-1, a, b, dp, curr, result);
        curr.pop_back();
    }
    else {
        if(dp[i-1][j] == dp[i][j])
            backtrack(i-1, j, a, b, dp, curr, result);

        if(dp[i][j-1] == dp[i][j])
            backtrack(i, j-1, a, b, dp, curr, result);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int length = lcs(n, m, a, b, dp);
    cout << "Length of LCS = " << length << "\n";

    // Find ALL LCS
    set<vector<int>> allLCS;
    vector<int> curr;

    backtrack(n, m, a, b, dp, curr, allLCS);

    cout << "All LCS sequences:\n";
    for(auto &seq : allLCS){
        for(int x : seq) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
