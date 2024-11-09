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
    cout << '\n';
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
    Node* ptr1=head1;
    Node* ptr2=head2;    
    Node* head=nullptr;    
    Node* curr=nullptr;
    while(ptr1!=nullptr && ptr2 !=nullptr){
        if(ptr1->data==ptr2->data){
        if(head==nullptr){
            Node* temp=new Node(ptr1->data);
            head=temp;
            curr=temp;
        }
        else{
            Node* temp=new Node(ptr1->data);
            curr->next=temp;
            curr=curr->next;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    else{
        if(ptr1->data<ptr2->data){
            ptr1=ptr1->next;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    }
    return head;
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
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *result = obj.findIntersection(head1, head2);

        printList(result);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends