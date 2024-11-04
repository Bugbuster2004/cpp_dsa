//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // Base case: if head is null or there is only one element in the list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // Step 1: Split the linked list into two halves
        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;
        // Disconnect the first half from the second half
        middle->next = nullptr;
        // Step 2: Recursively sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);
        // Step 3: Merge the sorted halves
        Node* sortedList = merge(left, right);
        return sortedList;
    }
    // Function to find the middle of the linked list using the slow and fast pointer method
    Node* getMiddle(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* slow = head;
        Node* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        Node* result = nullptr;

        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends