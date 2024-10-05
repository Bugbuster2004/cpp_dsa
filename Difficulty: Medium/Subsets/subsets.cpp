//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
   void solve(vector<int>& a, vector<vector<int>> &ans, vector<int> output, int index){
       if(index>= a.size()){
           ans.push_back(output);
           return;
       }
       
       
       //exclude
       solve(a, ans, output, index+1);
       
       //include
       
       int element = a[index];
       output.push_back(element);
       
       solve(a, ans, output, index+1);
   }
  
  
  
  
    vector<vector<int> > subsets(vector<int>& a) {
        // code here
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(a, ans, output, index);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends