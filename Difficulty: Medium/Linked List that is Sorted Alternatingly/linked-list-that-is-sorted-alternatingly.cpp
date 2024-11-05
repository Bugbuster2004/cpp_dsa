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
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sort(Node* head) {
        // Step 1: Store all values in a vector
        std::vector<int> values;
        Node* temp = head;
        while (temp != NULL) {
            values.push_back(temp->data);
            temp = temp->next;
        }

        // Step 2: Sort the values in ascending order
        std::sort(values.begin(), values.end());

        // Step 3: Create a new sorted linked list using the sorted values
        Node* dummy = new Node(0);  // Dummy node to simplify list creation
        Node* it = dummy;
        
        for (int val : values) {
            it->next = new Node(val);  // Create a new node for each value
            it = it->next;
        }

        // Step 4: Return the new head, skipping the dummy node
        return dummy->next;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t;
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
        }

        Solution ob;
        Node* newHead = ob.sort(head);
        printList(newHead);
        freeList(newHead);
    }

    return 0;
}

// } Driver Code Ends