#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Dijkstra with string vertices
    pair<int, vector<string>> dijkstra(
        unordered_map<string, vector<pair<string,int>>>& graph,
        string src,
        string dest
    ) {
        unordered_map<string, int> dist;
        unordered_map<string, string> parent;

        // Initialize all distances to infinity
        for (auto &node : graph)
            dist[node.first] = INT_MAX;

        // Min-heap {distance, node}
        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            greater<pair<int,string>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});
        parent[src] = "";

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (node == dest) break;  // Early stop if destination reached

            for (auto &nbr : graph[node]) {
                string nextNode = nbr.first;
                int wt = nbr.second;

                if (cost + wt < dist[nextNode]) {
                    dist[nextNode] = cost + wt;
                    parent[nextNode] = node;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // No path exists
        if (dist[dest] == INT_MAX)
            return {INT_MAX, {}};

        // Reconstruct path
        vector<string> path;
        string cur = dest;
        while (cur != "") {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());

        return {dist[dest], path};
    }
};

int main() {
    Solution sol;

    // -----------------------------
    // Example Graph (String Nodes)
    // -----------------------------
    unordered_map<string, vector<pair<string,int>>> graph;

    graph["A"] = { {"B", 4}, {"C", 1} };
    graph["B"] = { {"E", 4} };
    graph["C"] = { {"B", 2}, {"D", 4} };
    graph["D"] = { {"E", 4} };
    graph["E"] = {};

    string src = "A";
    string dest = "E";

    auto result = sol.dijkstra(graph, src, dest);

    int cost = result.first;
    vector<string> path = result.second;

    if (cost == INT_MAX) {
        cout << "No path exists between " << src << " and " << dest << endl;
        return 0;
    }

    cout << "Shortest Cost = " << cost << "\n";
    cout << "Path: ";
    for (auto &x : path) cout << x << " ";
    cout << endl;

    return 0;
}
