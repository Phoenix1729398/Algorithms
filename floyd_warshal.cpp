#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

class Solution {
public:
    vector<vector<int>> nextNode;
    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        nextNode.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] != INF && i != j)
                    nextNode[i][j] = j;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {

                        dist[i][j] = dist[i][k] + dist[k][j];
                        nextNode[i][j] = nextNode[i][k];
                    }
                }
            }
        }
    }
    vector<int> getPath(int src, int dest) {
        if (nextNode[src][dest] == -1)
            return {}; 
        vector<int> path;
        path.push_back(src);
        while (src != dest) {
            src = nextNode[src][dest];
            path.push_back(src);
        }
        return path;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    Solution obj;
    obj.floydWarshall(dist);
    int src, dest;
    cin >> src >> dest;
    vector<int> path = obj.getPath(src, dest);
    if (path.empty()) {
        cout << "No path exists\n";
    } else {
        cout << "Shortest path: ";
        for (int x : path) cout << x << " ";
        cout << "\nDistance = " << dist[src][dest] << "\n";
    }
    return 0;
}
