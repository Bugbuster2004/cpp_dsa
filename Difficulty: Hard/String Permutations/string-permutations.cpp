//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(int index, vector<string> &ans, string S){
        if(index>=S.size()){
            ans.push_back(S);
            return;
            
        }
        
        for(int j = index; j < S.size(); j++){
            swap(S[index], S[j]);
            solve(index+1, ans, S);
            swap(S[index], S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        int index = 0;
        solve(0, ans, S);
        sort(ans.begin(), ans.end());  // Sort the permutations lexicographically

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends