//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unordered_map<int, vector<char>> map;
    
    void helper(string curr, int index, int N, int a[], vector<string> &res){
        if(index == N){
            res.push_back(curr);
            return;
        }

        for(auto c: map[a[index]]){
            helper(curr + c, index + 1, N, a, res);
        }
    }

    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Initialize the map for the digits with corresponding characters
        map[2] = {'a', 'b', 'c'};
        map[3] = {'d', 'e', 'f'};
        map[4] = {'g', 'h', 'i'};
        map[5] = {'j', 'k', 'l'};
        map[6] = {'m', 'n', 'o'};
        map[7] = {'p', 'q', 'r', 's'};
        map[8] = {'t', 'u', 'v'};
        map[9] = {'w', 'x', 'y', 'z'};
        
        // Create a vector to store the result
        vector<string> res;
        
        // Call the helper function to generate all possible words
        helper("", 0, N, a, res);
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends