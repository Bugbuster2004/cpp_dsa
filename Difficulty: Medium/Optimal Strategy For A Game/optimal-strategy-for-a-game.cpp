//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    int dp[1001][1001];  // Global DP array
    
    // Recursive function to solve the problem
    int solve(int i, int j, int a[]) {
        if (i > j) return 0;  // Base case: if no coins are left
        
        if (dp[i][j] != -1) return dp[i][j];  // Use memoized result
        
        // Choice 1: Pick the first coin
        int x = a[i] + min(solve(i + 2, j, a), solve(i + 1, j - 1, a));
        
        // Choice 2: Pick the last coin
        int y = a[j] + min(solve(i, j - 2, a), solve(i + 1, j - 1, a));
        
        // Return the maximum of the two choices
        return dp[i][j] = max(x, y);
    }
    
public:
    long long maximumAmount(int n, int arr[]){
        memset(dp, -1, sizeof(dp));  // Initialize global dp array with -1
        return solve(0, n - 1, arr);  // Start solving the problem
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends