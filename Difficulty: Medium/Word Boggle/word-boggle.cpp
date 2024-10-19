//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
// Function to perform DFS and search for the word in the board
public:
bool solve(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int index) {
    // If all characters of the word are matched
    if (index == word.size()) return true;
    
    // Boundary checks and if the current character doesn't match or the cell is already visited
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
        return false;
    }

    // Mark the current cell as visited
    visited[i][j] = true;

    // Explore 8 possible directions: (left, right, up, down and diagonals)
    vector<int> rowDir = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> colDir = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Explore all directions
    for (int d = 0; d < 8; ++d) {
        if (solve(board, word, visited, i + rowDir[d], j + colDir[d], index + 1)) {
            return true;
        }
    }

    // Backtrack: unmark the current cell as visited for future searches
    visited[i][j] = false;
    return false;
}

// Function to check if a word exists in the board
bool exists(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Start search from every cell
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0]) {  // First character matches
                if (solve(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Main function to find all words from the dictionary that can be formed in the board
vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    vector<string> res;

    // Check for each word in the dictionary if it can be found in the board
    for (int i = 0; i < dictionary.size(); ++i) {
        string word = dictionary[i];
        if (exists(board, word)) {
            res.push_back(word);
        }
    }

    return res;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends