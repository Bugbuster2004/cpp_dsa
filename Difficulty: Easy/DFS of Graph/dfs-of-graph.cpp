//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to perform DFS traversal of the graph
    void dfs(int src, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& vis) {
        vis[src] = true;
        ans.push_back(src);

        for (auto child : adj[src]) {
            if (!vis[child]) {
                dfs(child, adj, ans, vis);
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of nodes
        vector<int> ans;
        vector<bool> vis(n, false); // Visited array

        // Perform DFS starting from node 0
        dfs(0, adj, ans, vis);

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends