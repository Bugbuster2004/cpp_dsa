//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    // Function to find the largest number after k swaps.
    void findMaximumNumUtil(string &str, int k, string &max_str, int idx)
    {
        // Base case: If no swaps are left or we've reached the end of the string.
        if (k == 0)
            return;

        int n = str.length();
        char max_char = str[idx];

        // Find the maximum digit after the current index.
        for (int i = idx + 1; i < n; i++)
        {
            if (str[i] > max_char)
                max_char = str[i];
        }

        // If the current character is already the maximum, no need to swap.
        // We still recurse on the next character, but without decrementing `k`.
        if (max_char != str[idx])
            k--;

        // Try swapping the current character with each occurrence of the max_char.
        for (int i = idx; i < n; i++)
        {
            if (str[i] == max_char)
            {
                // Swap the current index with the found max_char index.
                swap(str[idx], str[i]);

                // Update the maximum string if the current one is larger.
                if (str.compare(max_str) > 0)
                    max_str = str;

                // Recur for the next part of the string.
                findMaximumNumUtil(str, k, max_str, idx + 1);

                // Backtrack to the original state.
                swap(str[idx], str[i]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        // Initialize the maximum number as the input string.
        string max_str = str;

        // Call the utility function starting from index 0.
        findMaximumNumUtil(str, k, max_str, 0);

        // Return the largest number found.
        return max_str;
    }
};


//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends