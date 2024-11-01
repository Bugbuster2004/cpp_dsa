//{ Driver Code Starts
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


// } Driver Code Ends
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    // Function to delete the middle node of the linked list
    Node* deleteMid(Node* head) {
        // If the list has only one node, return NULL
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        // Initialize two pointers: slow and fast
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;  // To keep track of the node before slow
        
        // Move fast pointer twice as fast as the slow pointer
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        // 'slow' is now pointing to the middle node, 'prev' is just before it
        prev->next = slow->next;  // Remove the middle node
        
        delete slow;  // Free the memory of the middle node
        
        return head;  // Return the head of the modified list
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

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
        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends