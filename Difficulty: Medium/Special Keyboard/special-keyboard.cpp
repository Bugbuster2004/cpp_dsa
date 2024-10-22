//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    long long int optimalKeys(int N) {
        // If N <= 6, the maximum number of A's is just N (pressing A repeatedly)
        if (N <= 6) return N;

        // DP array to store the maximum A's we can get with i keystrokes
        long long dp[N + 1];

        // Fill dp[] for N <= 6
        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        // For N > 6, calculate the maximum A's we can get
        for (int i = 7; i <= N; i++) {
            dp[i] = 0; // Initialize with 0

            // Try different break points (where we stop typing A's and start using Ctrl operations)
            for (int j = i - 3; j >= 1; j--) {
                // Max A's by using j keystrokes to type, then Ctrl-A, Ctrl-C, and (i-j-1) Ctrl-V's
                dp[i] = std::max(dp[i], dp[j] * (i - j - 1));
            }
        }

        // The answer is the maximum A's we can get with N keystrokes
        return dp[N];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends