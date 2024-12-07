//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int, int>> q; // To store {row, col} of rotten oranges
        int freshCount = 0; // Count of fresh oranges
        int time = 0;

        // Step 1: Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 2) {
                    q.push({i, j}); // Rotten orange
                } else if (mat[i][j] == 1) {
                    ++freshCount; // Fresh orange
                }
            }
        }

        // If no fresh orange, no time required
        if (freshCount == 0) return 0;

        // Step 2: BFS to spread the rot
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        while (!q.empty()) {
            int size = q.size();
            bool rottenThisTurn = false;

            for (int i = 0; i < size; ++i) {
                pair<int, int> current = q.front();
                q.pop();
                int x = current.first;
                int y = current.second;

                // Try all four directions
                for (auto dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    // Check if the new position is valid and has a fresh orange
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2; // Mark as rotten
                        q.push({nx, ny}); // Add to queue
                        --freshCount; // Decrement fresh count
                        rottenThisTurn = true;
                    }
                }
            }

            // Increment time if at least one orange rotted in this turn
            if (rottenThisTurn) ++time;
        }

        // Step 3: Check if all fresh oranges are rotten
        return freshCount == 0 ? time : -1;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends