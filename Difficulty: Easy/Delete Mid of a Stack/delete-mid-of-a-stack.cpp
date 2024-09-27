//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Helper function to remove the middle element recursively.
    void deleteMiddleHelper(stack<int>& s, int currentIndex, int midIndex) {
        // Base case: When the current index reaches the middle index
        if (currentIndex == midIndex) {
            s.pop();  // Remove the middle element
            return;
        }
        
        // Save the top element and pop it
        int temp = s.top();
        s.pop();
        
        // Recursive call to remove the next element
        deleteMiddleHelper(s, currentIndex + 1, midIndex);
        
        // Push the saved elements back to the stack after the middle element is removed
        s.push(temp);
    }

    // Function to delete the middle element of a stack
    void deleteMid(stack<int>& s, int sizeOfStack) {
        if (sizeOfStack == 0) {
            return; // Edge case: empty stack
        }

        int midIndex = sizeOfStack / 2;  // Find the index of the middle element
        
        deleteMiddleHelper(s, 0, midIndex);  // Start recursion to remove the middle element
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends