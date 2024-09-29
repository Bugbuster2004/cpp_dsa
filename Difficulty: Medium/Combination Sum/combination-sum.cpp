//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    // Function to return a list of indexes denoting the required combinations whose sum is equal to given number.
    void solve(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        
        // If the target is 0, we've found a valid combination.
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Loop through the array starting from index
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicates
            if (i > index && arr[i] == arr[i - 1]) continue;
            
            // If the current element is greater than the remaining target, no need to proceed further
            if (arr[i] > target) break;

            // Include the current element and recurse
            ds.push_back(arr[i]);
            solve(i, target - arr[i], arr, ans, ds);  // `i` allows the same element to be used again
            ds.pop_back();  // Backtrack
        }
    }
 
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        // Sort the array to handle duplicates and ensure combinations are generated in non-decreasing order
        sort(A.begin(), A.end());
        
        // Call the recursive function
        solve(0, B, A, ans, ds);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends