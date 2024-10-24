//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int N, int src, int dest, int aux, int &count, int n, vector<int>& result) {
        // Base case
        if (N == 0) return;

        // Move N-1 plates from source to auxiliary using destination as helper
        solve(N - 1, src, aux, dest, count, n, result);
        
        // Increment the move counter
        count++;

        // If the current move count matches the nth move, record the move
        if (count == n) {
            result = {src, dest};
            return;
        }

        // Move N-1 plates from auxiliary to destination using source as helper
        solve(N - 1, aux, dest, src, count, n, result);
    }

    vector<int> shiftPile(int N, int n) {
        // To store the nth move
        vector<int> result;
        // Initialize the move counter
        int count = 0;
        // Call the recursive solver to find the nth move
        solve(N, 1, 3, 2, count, n, result);
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends