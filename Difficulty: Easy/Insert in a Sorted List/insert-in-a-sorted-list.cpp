//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*
structure of the node of the list is as
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
    // Function to insert an element in a sorted linked list
    Node* sortedInsert(Node* head, int x) {
        // Create a new node with the value to be inserted
        Node* newNode = new Node(x);
        
        // Case 1: Insert at the beginning if head is NULL or x is smaller than head's data
        if (head == NULL || x < head->data) {
            newNode->next = head;
            return newNode; // New node becomes the new head
        }
        
        // Case 2: Traverse the list to find the correct position for insertion
        Node* temp = head;
        
        while (temp->next != NULL && temp->next->data < x) {
            temp = temp->next; // Move to the next node until we find the position
        }
        
        // Insert the new node at the found position
        newNode->next = temp->next;
        temp->next = newNode;
        
        return head; // Return the head of the modified list
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main() {

    int T, i, n, l;
    cin >> T;
    cin.ignore();

    while (T--) {
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
        Node *head = new Node(data);
        Node *tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after the integer input

        Solution ob;
        Node *result = ob.sortedInsert(head, k);
        print(result);
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends