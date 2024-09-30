//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

  class Solution {
public:
    vector<int> Series(int n) {
        const int MOD = 1e9 + 7;  // Modulo value
        vector<int> fibonacci;  // To store the Fibonacci series
        
        // Handle base cases
        if (n >= 0) fibonacci.push_back(0);  // F(0) = 0
        if (n >= 1) fibonacci.push_back(1);  // F(1) = 1
        
        // Calculate Fibonacci series for all terms up to 'n'
        for (int i = 2; i <= n; ++i) {
            int next_term = (fibonacci[i-1] + fibonacci[i-2]) % MOD;  // F(i) = F(i-1) + F(i-2) % MOD
            fibonacci.push_back(next_term);
        }
        
        return fibonacci;  // Return the Fibonacci series
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends