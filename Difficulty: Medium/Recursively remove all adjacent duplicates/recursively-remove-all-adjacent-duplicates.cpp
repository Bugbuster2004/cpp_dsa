//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  string rem (string s1){
      string ans;
      int n = s1.size();
      int i = 0;
      while(i<n){
          if(i<n-1 && s1[i]==s1[i+1]){
              while(i<n-1 && s1[i]== s1[i+1]){
                  i++;
              }
              }else{
                  ans.push_back(s1[i]);
          }
          
          i++;
      }
      return ans;
        }
    string rremove(string s) {
        // code here
        
        string s2;
        while(s2.size()!= s.size()){
            
            s2 = s;
            s = rem(s);
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends