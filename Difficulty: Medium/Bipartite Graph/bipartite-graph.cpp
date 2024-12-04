//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1); // -1 indicates no color assigned yet

        // Check for each component of the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // If the node is not colored
                queue<int> q;
                q.push(i);
                color[i] = 0; // Assign the first color

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            // Assign the opposite color to the neighbor
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            // If the neighbor has the same color, the graph is not bipartite
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends