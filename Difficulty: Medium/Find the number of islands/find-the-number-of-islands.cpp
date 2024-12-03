//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void bfs(int row, int col, vector<vector<char>> grid, vector<vector<bool>> &visited){
      queue<pair<int, int>> q;
      visited[row][col] = true;
      q.push({row, col});
      
      int n = grid.size();
      int m = grid[0].size();
      
      while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          
          q.pop();
          
          for(int i=-1; i<=1; i++){
              for(int j=-1; j<=1; j++){
                  int nrow = row+i;
                  int ncol = col+j;
                  
                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]== '1' && !visited[nrow][ncol]){
                      visited[nrow][ncol] = true;
                      q.push({nrow, ncol});
                  }
              }
          }
      }
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m ;j++){
                if(!visited[i][j] && grid[i][j] =='1'){
                    ans++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends