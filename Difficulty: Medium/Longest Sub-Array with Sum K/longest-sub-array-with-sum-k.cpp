//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        unordered_map<int, int> prefix_map; // To store the first occurrence of a prefix sum
        int prefix_sum = 0; // Initialize prefix sum
        int max_length = 0; // To store the maximum length of the subarray

        for (int i = 0; i < arr.size(); i++) {
            prefix_sum += arr[i]; // Update the prefix sum

            // If the prefix sum equals k, update max_length
            if (prefix_sum == k) {
                max_length = i + 1;
            }

            // If (prefix_sum - k) is found in prefix_map, update max_length
            if (prefix_map.find(prefix_sum - k) != prefix_map.end()) {
                max_length = max(max_length, i - prefix_map[prefix_sum - k]);
            }

            // If prefix_sum is not already in the map, store it with its index
            if (prefix_map.find(prefix_sum) == prefix_map.end()) {
                prefix_map[prefix_sum] = i;
            }
        }

        return max_length;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends