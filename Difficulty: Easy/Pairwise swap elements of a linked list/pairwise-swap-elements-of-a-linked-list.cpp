//{ Driver Code Starts


#include <bits/stdc++.h>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution {
  public:
    Node* pairWiseSwap(Node* head) {
        // If the list is empty or has only one node, return head
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // The new head will be the second node after the first swap
        Node* newHead = head->next;
        
        // Initialize pointers for swapping
        Node* prev = NULL;
        Node* curr = head;
        
        // Loop to swap nodes in pairs
        while (curr != NULL && curr->next != NULL) {
            Node* nextPair = curr->next->next; // The start of the next pair
            Node* second = curr->next;         // The second node in the current pair
            
            // Swap the nodes
            second->next = curr;
            curr->next = nextPair;

            // Connect the previous pair with the current swapped pair
            if (prev != NULL) {
                prev->next = second;
            }

            // Move pointers for the next pair
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t input

    while (t--) {
        vector<int> arr;
        string input;

        // Read the array of linked list elements
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl; // handle empty input
            continue;
        }

        // Create linked list from the input array
        Node* head = new Node(arr[0]);
        Node* tail = head;
        map<Node*, int> mp;
        mp[head] = head->data;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
            mp[tail] = tail->data;
        }

        Node* failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        Node* temp = head;
        while (temp) {
            if (mp[temp] != temp->data) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends