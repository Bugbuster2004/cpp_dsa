//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  vector<int> g[15];
  int ans = 0;
  void dfs(int s, int d){
      if(s==d){
          ans++;
          return;
      }
      for(auto e:g[s]){
          dfs(e,d);
      }
  }
    int possible_paths(vector<vector<int>> &edges, int n, int start, int destination) {
        // Code here
        ans = 0;
        for(int i=0; i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
        }
        dfs(start,destination);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends