//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    
    void solve(vector<string> &ans, int n, int open , int close, string current){
        if(current.size() == n*2){
            ans.push_back(current);
            return ;
        }
        
        // case 1 when open<n add (
        if(open < n) solve(ans, n, open+1, close, current + "(");
        if(close < open) solve(ans, n, open , close+1, current + ")");
        
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        solve(ans, n, 0, 0, "");
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends