//{ Driver Code Starts
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

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        vector<int> ans;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        // Traverse to the end of head1 and link it to head2
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp2; // Connect head1's last node to head2

        // Reinitialize temp1 to head1
        temp1 = head1;

        // Push all elements from the merged list to the vector
        while(temp1 != NULL) {
            ans.push_back(temp1->data);
            temp1 = temp1->next;
        }
        
        // Sort the vector
        sort(ans.begin(), ans.end());

        // Reinitialize temp1 to head1 again to overwrite values with sorted data
        temp1 = head1;
        for(int i = 0; i < ans.size(); i++) {
            temp1->data = ans[i];
            temp1 = temp1->next;
        }

        return head1;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends