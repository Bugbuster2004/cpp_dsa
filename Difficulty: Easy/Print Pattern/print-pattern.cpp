//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<int>& ans, int n, int N) {
        // Add current value of n to the result list
        ans.push_back(n);
        
        // Base case: if n <= 0, 
        if(n <= 0) return;

        // Recursively decrease n by 5
        solve(ans, n - 5, N);
        
        // since the  copies are formed at each recur call so the prev value will be pushed into the array
        ans.push_back(n);
    }

    vector<int> pattern(int N) {
        vector<int> ans;
        solve(ans, N, N);
        return ans;
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends