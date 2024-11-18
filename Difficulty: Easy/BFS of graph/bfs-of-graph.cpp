//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n  = adj.size();
        vector<int> bfs;
        queue<int> q;
        //visited 
        vector<int> vis(n,0);
        
        q.push(0);
        
        vis[0] = 1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            bfs.push_back(frontNode);
            
            for(auto item: adj[frontNode]){
                if(vis[item]!=1){
                    q.push(item);
                    vis[item] = 1;
                }
            }
        }
        
        return bfs;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends