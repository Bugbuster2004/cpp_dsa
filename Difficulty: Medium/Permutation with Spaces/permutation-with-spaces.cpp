//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
 void solve(int index, vector<string> &res, string str, string s){
     if(index == s.size()-1){
         str+=s[index];
         res.push_back(str);
         return;
     }
     
     
     solve(index+1, res, str+s[index]+" ", s);
     solve(index+1, res, str+s[index], s);
 }
 
 
 
    vector<string> permutation(string s) {
        // Code Here
        vector<string> res;
        string str = "";
        solve(0, res, str, s);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends