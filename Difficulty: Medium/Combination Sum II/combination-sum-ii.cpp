//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> ans; // to store all unique combinations

    void solve(vector<int>& arr, int n, int k, int index, vector<int>& ds) {
        if(k == 0) {
            ans.push_back(ds); // found a valid combination
            return;
        }

        for(int i = index; i < n; i++) {
            // Skip duplicates
            if(i > index && arr[i] == arr[i - 1]) continue;
            
            // If the current element is greater than the remaining sum, break out of the loop
            if(arr[i] > k) break;

            // Include the current element in the combination
            ds.push_back(arr[i]);

            // Move to the next element and reduce the target sum (k - arr[i])
            solve(arr, n, k - arr[i], i + 1, ds); 

            // Backtrack: remove the current element from the combination
            ds.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        // Sort the array to ensure non-decreasing order in combinations
        sort(arr.begin(), arr.end());

        // Temporary data structure to store the current combination
        vector<int> ds;

        // Call the recursive function starting from index 0
        solve(arr, n, k, 0, ds);

        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends