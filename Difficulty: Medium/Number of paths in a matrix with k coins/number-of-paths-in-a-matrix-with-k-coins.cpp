//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    // 3D DP array, with size reduced to handle up to k coins
    long long dp[101][101][101]; 

    // Recursive function with memoization
    long long solve(int i, int j, int currentCoins, int n, int k, vector<vector<int>>& arr) {
        // Base case: If out of bounds
        if (i >= n || j >= n) {
            return 0;
        }

        // Add current cell's coins to the total
        currentCoins += arr[i][j];

        // If we exceed k coins, stop this path
        if (currentCoins > k) {
            return 0;
        }

        // Base case: If we reach the bottom-right corner
        if (i == n - 1 && j == n - 1) {
            // Check if exactly k coins are collected
            return (currentCoins == k) ? 1 : 0;
        }

        // If already calculated, return the stored result
        if (dp[i][j][currentCoins] != -1) {
            return dp[i][j][currentCoins];
        }

        // Recurse by moving right and down
        long long right = solve(i, j + 1, currentCoins, n, k, arr);
        long long down = solve(i + 1, j, currentCoins, n, k, arr);

        // Store the result in dp table and return it
        return dp[i][j][currentCoins] = right + down;
    }

    long long numberOfPath(int n, int k, vector<vector<int>>& arr) {
        // Initialize the dp array to -1 for memoization
        memset(dp, -1, sizeof(dp));

        // Start from the top-left corner with 0 collected coins
        return solve(0, 0, 0, n, k, arr);
    }
};




//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends