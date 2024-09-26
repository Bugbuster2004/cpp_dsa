//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void solve(string S, vector<string> &ans, int index){
        if(index >= S.size()){
            ans.push_back(S);
            return;
        }
        
        // Traverse each character from index to end of string
        for(int j = index; j < S.size(); j++){
            swap(S[index], S[j]);  // Swap current character with the character at index j
            solve(S, ans, index+1);  // Recursively call for the next index
            swap(S[index], S[j]);  // Backtrack
        }
    }
    
    public:
    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        int index = 0;
        solve(S, ans, index);  // Generate all permutations
        sort(ans.begin(), ans.end());  // Sort permutations in lexicographical order
        ans.erase(unique(ans.begin(), ans.end()), ans.end());  // Remove duplicates if any
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends