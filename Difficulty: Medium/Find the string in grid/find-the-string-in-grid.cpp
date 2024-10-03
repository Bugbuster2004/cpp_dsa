//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:

    bool f(int index, int row, int col, int d1, int d2, vector<vector<char>> &grid, string &word){
        int n = grid.size();
        int m = grid[0].size();

        if(index == word.size()){
            return true;
        }

        // Check boundaries and character mismatch
        if(row < 0 || row >= n || col < 0 || col >= m || word[index] != grid[row][col]){
            return false;
        }

        // Recursively move in the given direction
        return f(index+1, row+d1, col+d2, d1, d2, grid, word);
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string word){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ds;

        // Define direction vectors for 8 possible directions
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Loop through each cell in the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Check if the first character matches
                if(grid[i][j] == word[0]){
                    // Check in all 8 possible directions
                    for(int k = 0; k < 8; k++){
                        if(f(1, i + dx[k], j + dy[k], dx[k], dy[k], grid, word)){
                            ds.push_back({i, j});
                            break;  // We found the word starting at (i, j), no need to check more directions
                        }
                    }
                }
            }
        }

        return ds;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends