//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // If start is already equal to end
        if (start == end) return 0;

        // Queue to store pairs of (current value, steps taken)
        queue<pair<int, int>> q;
        q.push({start, 0});

        // Distance array to track minimum steps to reach a number
        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        // Modulo constant
        int mod = 100000;

        // Perform BFS
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Explore all possible multiplications
            for (auto it : arr) {
                int num = (it * node) % mod;

                // If we find a shorter path to 'num'
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;

                    // If 'end' is reached
                    if (num == end) {
                        return steps + 1;
                    }

                    // Push to queue
                    q.push({num, steps + 1});
                }
            }
        }

        // If 'end' is unreachable
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends