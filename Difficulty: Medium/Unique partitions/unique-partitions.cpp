//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
  void solve(vector<vector<int>> &ans, vector<int> &curr, int i, int n){
      
      if(n==0){
          ans.push_back(curr);
          return;
      }
      
      if(i<1){
          return ;
      }
      
      if(i<=n){
          curr.push_back(i);
          solve(ans, curr, i, n-i);
          curr.pop_back();
          solve(ans, curr, i-1, n);
      }else{
            solve(ans,curr, i-1, n);
      }
  }
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, n, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        vector<vector<int>> ans = ob.UniquePartitions(n);
        for (auto i : ans)
            for (auto j : i)
                cout << j << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends