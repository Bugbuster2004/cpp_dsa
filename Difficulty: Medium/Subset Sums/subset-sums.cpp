//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
  void func(int index, int sum, vector<int> &arr, int n, vector<int> &subSet){
      if(index == n){
          subSet.push_back(sum);
          return ;
      }
      
      //pick element
      func(index+1, sum+arr[index], arr, n, subSet);
      
      //do not pick
      func(index+1, sum, arr, n, subSet);
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> subSet;
        func(0,0, arr, n, subSet);
        return subSet;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends