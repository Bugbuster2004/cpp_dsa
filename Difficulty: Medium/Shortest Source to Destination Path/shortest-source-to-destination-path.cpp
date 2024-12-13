//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // Edge case: If the start or end cell is blocked
        if (A[0][0] == 0 || A[X][Y] == 0) return -1;
        
        // BFS initialization
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        A[0][0] = 0; // Mark as visited
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            int dis = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            
            // Check if we reached the target
            if (i == X && j == Y) return dis;
            
            // Explore all 4 possible directions
            for (int k = 0; k < 4; k++) {
                int newi = i + dx[k];
                int newj = j + dy[k];
                
                // Check if within bounds and unvisited
                if (newi >= 0 && newj >= 0 && newi < N && newj < M && A[newi][newj] == 1) {
                    A[newi][newj] = 0; // Mark as visited
                    q.push({dis + 1, {newi, newj}});
                }
            }
        }
        
        // Target not reachable
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends