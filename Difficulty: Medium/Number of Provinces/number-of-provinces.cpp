//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int node, vector<vector<int>> &adjlist, int vis[]) {
        vis[node] = 1;
        for (auto it : adjlist[node]) {
            if (!vis[it]) {
                dfs(it, adjlist, vis);
            }
        }
    }

  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Create adjacency list
        vector<vector<int>> adjlist(V); // Fixed size for adjacency list
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) { // Check adjacency matrix
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0}; // Visited array
        int cnt = 0;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjlist, vis);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends