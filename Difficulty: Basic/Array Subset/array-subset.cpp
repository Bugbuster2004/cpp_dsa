//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Create a frequency map for array a
        unordered_map<int, int> freqMap;
        for (int num : a) {
            freqMap[num]++;
        }

        // Check if b[] is a subset of a[]
        for (int num : b) {
            if (freqMap[num] > 0) {
                freqMap[num]--; // Decrement the count for the current element
            } else {
                return false; // Element not found or insufficient occurrences
            }
        }

        return true; // All elements in b[] are accounted for
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
//     vector<int> b = {11, 3, 7, 1, 7};
//     if (sol.isSubset(a, b)) {
//         cout << "Yes\n";
//     } else {
//         cout << "No\n";
//     }
//     return 0;
// }

 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a1, a2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a1.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            a2.push_back(number);
        }
        Solution s;
        bool ans = s.isSubset(a1, a2);
        if (ans) {
            cout << "Yes"
                 << "\n";
        } else {
            cout << "No"
                 << "\n";
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends