//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        Node* temp = head;
        int count_0 = 0, count_1 = 0, count_2 = 0;
        
        // First pass to count 0s, 1s, and 2s
        while (temp != NULL) {
            if (temp->data == 0) {
                count_0++;
            } else if (temp->data == 1) {
                count_1++;
            } else if (temp->data == 2) {
                count_2++;
            }
            temp = temp->next;
        }
        
        // Second pass to update the list with 0s, 1s, and 2s in order
        temp = head;
        while (temp != NULL) {
            if (count_0 > 0) {
                temp->data = 0;
                count_0--;
            } else if (count_1 > 0) {
                temp->data = 1;
                count_1--;
            } else if (count_2 > 0) {
                temp->data = 2;
                count_2--;
            }
            temp = temp->next;
        }

        return head;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends