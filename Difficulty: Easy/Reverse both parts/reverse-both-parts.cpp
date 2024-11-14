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
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
       Node *reverse(Node *head, int k)
    {
        // code here
        Node *curr=head,*prev=NULL,*agli;
        int node=0;
        while(curr){
            node++;
            agli = curr->next;
            curr->next = prev;
            prev = curr;
            curr=agli;
        }
        node=node-k-1;
        Node *temp = prev;
        while(node--){
            temp=temp->next;
        }
        head->next=prev;
        head=temp->next;
        temp->next=NULL;
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
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
        cout << "~" << endl;
    }
}
// } Driver Code Ends