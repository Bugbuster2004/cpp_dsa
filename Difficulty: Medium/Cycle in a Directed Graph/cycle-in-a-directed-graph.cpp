//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int node) {
        vis[node] = 1;
        path[node] = 1;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(adj, vis, path, it) == true) {
                    return true;
                }
            } else if (path[it]) {
                return true;
            }
        }
        
        path[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, path, i) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends