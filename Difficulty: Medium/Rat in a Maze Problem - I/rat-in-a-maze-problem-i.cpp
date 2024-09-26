//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to check if a cell is safe to move to.
    bool isSafe(int x, int y, vector<vector<int>> &mat, vector<vector<bool>> &visited, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
    }

    // Recursive function to find paths.
    void findPaths(int x, int y, vector<vector<int>> &mat, int n, vector<string> &paths, 
                   vector<vector<bool>> &visited, string path) {
        
        // Base case: If we reach the bottom-right corner
        if (x == n - 1 && y == n - 1) {
            paths.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = true;

        // Explore the four possible directions: Down, Left, Right, Up

        // Move Down (x+1, y)
        if (isSafe(x + 1, y, mat, visited, n)) {
            findPaths(x + 1, y, mat, n, paths, visited, path + 'D');
        }

        // Move Left (x, y-1)
        if (isSafe(x, y - 1, mat, visited, n)) {
            findPaths(x, y - 1, mat, n, paths, visited, path + 'L');
        }

        // Move Right (x, y+1)
        if (isSafe(x, y + 1, mat, visited, n)) {
            findPaths(x, y + 1, mat, n, paths, visited, path + 'R');
        }

        // Move Up (x-1, y)
        if (isSafe(x - 1, y, mat, visited, n)) {
            findPaths(x - 1, y, mat, n, paths, visited, path + 'U');
        }

        // Unmark the current cell (backtracking)
        visited[x][y] = false;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();  // Size of the matrix
        vector<string> paths;
        
        // If starting or ending cell is blocked, no path exists
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return paths;
        }

        // Visited array to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start finding paths from the top-left corner (0, 0)
        findPaths(0, 0, mat, n, paths, visited, "");
        
        return paths;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends