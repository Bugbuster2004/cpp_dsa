//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Helper function to reverse the linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to add 1 to the linked list
    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Add one to the reversed list
        Node* curr = head;
        int carry = 1; // Start with the carry as 1 since we are adding 1
        while (curr) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;

            // If there's no carry left, break out
            if (carry == 0) break;

            // Move to the next node
            if (!curr->next && carry) {
                // If we're at the end and there's still carry, add a new node
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }

        // Step 3: Reverse the list back to original order
        head = reverse(head);
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends