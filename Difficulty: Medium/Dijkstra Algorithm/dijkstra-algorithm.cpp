//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
public:
    // Function to find the shortest distance of all vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        set<pair<int, int>> st;
        vector<int> dis(adj.size(), 1e9);

        st.insert({0, src});
        dis[src] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int distance = it.first;
            st.erase(st.begin());

            for (auto edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;
 
                if (dis[neighbor] > dis[node] + weight) {
                    
                    if (dis[neighbor] != 1e9) {
                        st.erase({dis[neighbor], neighbor});
                    }
                    
                    dis[neighbor] = dis[node] + weight;
                    st.insert({dis[neighbor], neighbor});
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends