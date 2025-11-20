#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(V,1e9);
        pq.push({0,src});
        distance[src]=0;
        vector<int>parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dist+wt<distance[adjnode]){
                    distance[adjnode]=dist+wt;
                    parent[adjnode]=node;
                    pq.push({distance[adjnode],adjnode});
                }
            }
        }
        //printing the shortest path from src to dest if required
        // vector<int>path;
        // int node=dest;
        // while(parent[node]!=node){
        //     path.push_back(node);
        //     node=parent[node];
        // }
        // path.push_back(src);
        // reverse(path.begin(),path.end());
        // return path;
        return distance;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}