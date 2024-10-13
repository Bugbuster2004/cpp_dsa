//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
 

class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int index) {
    
        ans.push_back(output);
        
        
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates: if the current element is the same as the previous one,
            // and the previous one has not been used in this position, skip this element.
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Include the current element in the subset
            output.push_back(nums[i]);
            
            // Recur for the next elements starting from the next index
            solve(nums, ans, output, i + 1);
            
            // Backtrack: remove the last included element to explore other subsets
            output.pop_back();
        }
    }

    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> ans;  // To store all unique subsets
        vector<int> output;       // To store the current subset
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        solve(nums, ans, output, 0);     // Start recursion from index 0
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends