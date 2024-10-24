//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to count the number of non-crossing handshakes
    int count(int N) {
        // Base case: If there are no people, there's exactly one way (no handshakes)
        if (N == 0) {
            return 1;
        }

        int totalWays = 0;
        
        // Pair the first person with one of the others, and divide the rest into two groups
        for (int i = 0; i < N - 1; i += 2) {
            // Recursive calls: one for the first subproblem and another for the second subproblem
            int left = count(i);           // Handshakes in the group between the pair
            int right = count(N - i - 2);  // Handshakes in the group outside the pair
            totalWays += left * right;     // Multiply the ways of both subproblems
        }
        
        return totalWays;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends