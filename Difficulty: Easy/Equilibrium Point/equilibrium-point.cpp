//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
   int equilibriumPoint(vector<int> &arr) {
        // Your code here
        int sumRight=0;
        int sumLeft=0;
        int n= arr.size();
        int eqPoint = -1;
        for(int i = 1 ;i<n;i++)
        {
            sumRight +=arr[i];
        }
        if(sumLeft==sumRight){return 1;}
        for(int i =1;i<n;i++)
        {
            sumLeft = sumLeft + arr[i-1];
            sumRight = sumRight -arr[i];
            if(sumLeft==sumRight)
            {
                eqPoint = i+1;
                break;
            }
        }
        return eqPoint;

        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends