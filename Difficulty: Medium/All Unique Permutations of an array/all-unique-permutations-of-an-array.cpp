//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void solve(int index, vector<vector<int>> &ans, vector<int> &arr){
        // Base case: If the index is at the end, add the current permutation to the answer
        if(index >= arr.size()){
            ans.push_back(arr);
            return;
        }
        
        // Set to avoid duplicate elements being swapped at the same position
        unordered_set<int> swapped;
        
        for(int i = index; i < arr.size(); i++ ){
            // Skip duplicates
            if(swapped.find(arr[i]) != swapped.end()) continue;
            
            swapped.insert(arr[i]);
            
            // Swap to create a new permutation
            swap(arr[i], arr[index]);
            
            // Recurse with the next index
            solve(index + 1, ans, arr);
            
            // Swap back to restore the original array state
            swap(arr[i], arr[index]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        
        // Sort the array to ensure duplicates are adjacent
        sort(arr.begin(), arr.end());
        
        // Call the recursive function
        solve(0, ans, arr);
        
        // Sort the final list of permutations to ensure sorted order
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends