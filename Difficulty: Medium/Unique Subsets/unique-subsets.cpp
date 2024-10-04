//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void help(int i, vector<int>& arr, int n, vector<int>& subset, vector<vector<int>>& powerSet) {
        if (i == n) {
            powerSet.push_back(subset); // Add the current subset to the power set
            return;
        } else {
            // Pick the current element
            subset.push_back(arr[i]);
            help(i + 1, arr, n, subset, powerSet); // Recur to the next element
            subset.pop_back(); // Backtrack

            // Skip duplicates
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                i++;
            }
            help(i + 1, arr, n, subset, powerSet); // Recur without including the current element
        }
    }

    vector<vector<int>> AllSubsets( vector<int> arr, int n) {
        sort(arr.begin(), arr.end()); // Sort the array to handle duplicates
        vector<vector<int>> ans; // To store all unique subsets
        vector<int> subSet; // To store the current subset
        help(0, arr, n, subSet, ans); // Start the recursion
        sort(ans.begin(), ans.end()); // Sort the subsets
        return ans; // Return the result
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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