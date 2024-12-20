//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int i, vector<int> adj[], bool vis[], stack<int> &s) {
        vis[i] = true;
        for (auto x : adj[i]) {
            if (!vis[x]) {
                dfs(x, adj, vis, s);
            }
        }
        s.push(i);
    }
    void checkMother(int i, vector<int> adj[], bool vis[], int &c) {
        vis[i] = true;
        c++;
        for (auto x : adj[i]) {
            if (!vis[x]) {
                checkMother(x, adj, vis, c);
            }
        }
    }
    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[]) {
        bool vis[V];
        stack<int> s;

        // Step 1: Perform a DFS to find the last finished vertex
        for (int i = 0; i < V; i++) {
            vis[i] = false;
        }
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, s);
            }
        }
        // Step 2: Check if the top of the stack is a mother vertex
        for (int i = 0; i < V; i++) {
            vis[i] = false;
        }
        
        int c = 0;
        int candidate = s.top(); // Top of the stack is the potential mother vertex
        checkMother(candidate, adj, vis, c);

        if (c == V) {
            return candidate;
        } else {
            return -1;
        }
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends