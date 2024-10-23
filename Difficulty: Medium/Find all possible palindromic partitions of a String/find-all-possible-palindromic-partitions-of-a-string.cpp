//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve( int index, string S, vector<vector<string>> &res, vector<string> &path){
      if(index == S.size()){
          res.push_back(path);
          return ;
      }
      
      for(int i=index; i <S.size(); i++){
          if(isPalindrome(index, S, i)){
              path.push_back(S.substr(index, i-index+1));
              solve(i+1, S, res , path);
              path.pop_back();
          }
          
      }
  }
      
      bool isPalindrome(int start, string S, int end){
          while(start <=end){
              if(S[start++]!= S[end--]){
                  return false;
              }
          }
      return true;
      }
      
 
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> res;
        vector<string> path;
        solve(0, S, res, path);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends