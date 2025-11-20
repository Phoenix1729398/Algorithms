#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    pair<int, vector<array<int,3>>> spanningTree(
        int V, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<
            array<int,3>, 
            vector<array<int,3>>, 
            greater<array<int,3>>
        > pq;
        vector<int> visited(V, 0);
        vector<array<int,3>> mstEdges;
        int mstWeight = 0;
        pq.push({0, 0, -1});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int wt = top[0];
            int node = top[1];
            int parent = top[2];
            if(visited[node]) continue;
            visited[node] = 1;
            mstWeight += wt;
            if(parent != -1){
                mstEdges.push_back({parent, node, wt});
            }
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edWt = it.second;
                if(!visited[adjNode]){
                    pq.push({edWt, adjNode, node});
                }
            }
        }
        return {mstWeight, mstEdges};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}