//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  
public:
  
  void solve(int sr, int sc, vector<vector<int>>& image,  vector<vector<int>> &ans, int newColor, int delRow[], int delCol[], int iniColor){
      ans[sr][sc] = newColor;
      int n = image.size();
      int m = image[0].size();
      
      for(int i=0; i<4; i++){
          int newRow = sr + delRow[i];
          int newCol = sc + delCol[i];
          if(newRow >=0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == iniColor && ans[newRow][newCol] != newColor){
              solve(newRow, newCol, image, ans, newColor, delRow, delCol, iniColor);
          }
      }
      
  }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        solve(sr, sc, image, ans, newColor, delRow, delCol, iniColor);
        
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends