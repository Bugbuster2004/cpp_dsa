//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        const long long MOD = 1e9+7;
        long long result = 0;
        long long currentNumber = 1;
        
        
        
        for(int i=1; i<=n ; i++){
            long long product = 1;
            for(int j=0; j<i; j++){
                 product = (product*currentNumber)%MOD;
                currentNumber++;
            }
            
            result = (result+product)%MOD;
            
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends