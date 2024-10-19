//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    const int MOD = 1e9 + 7; // Define the modulus
    
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> prev = {1}; // Start with the 1st row, i.e., [1]
        
        // Loop to generate Pascal's Triangle rows until the nth row
        for(int i = 1; i < n; i++) { // Start from 1 instead of 0
            vector<long long> curr(i + 1); // Current row will have i+1 elements
            curr[0] = 1; // First element of the row is always 1
            curr[i] = 1; // Last element of the row is always 1

            // Fill the middle elements by adding elements from the previous row
            for(int j = 1; j < i; j++) {
                curr[j] = (prev[j] + prev[j - 1]) % MOD; // Apply modulo to avoid overflow
            }

            prev = curr; // Update prev row to the current row
        }
        
        return prev; // Return the nth row (prev holds the result)
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends