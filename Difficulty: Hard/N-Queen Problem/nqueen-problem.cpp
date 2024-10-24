//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:

bool isSafe(int row, int col, vector<int> &board, int n){
     // Checking left side of the column
     for(int j = 0; j < col; j++) {
         // Checking if the queen in column `j` conflicts with the queen in column `col`
         if(board[j] == row || abs(board[j] - row) == abs(j - col)) {
             return false;
         }
     }
     return true;
}

void addSolution(vector<int> &board, vector<vector<int>> &ans, int n){
    vector<int> temp;
    
    // Convert the 0-based row indices to 1-based row indices
    for(int i = 0; i < n; i++) {
        temp.push_back(board[i] + 1); // Convert 0-based to 1-based
    }
    
    ans.push_back(temp); // Add to the list of solutions
}

void solve(int col,vector<vector<int> > &ans, vector<int> &board, int n){
    if(col == n){
        addSolution(board, ans, n);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            // Place the queen in the `row` in the current `col`
            board[col] = row;
            solve(col + 1, ans, board, n);
            // No need to reset since we'll overwrite `board[col]` with a new row in the next iteration
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<int> board(n, 0);  // Represents the row positions of queens for each column
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    
    return ans;
}
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends