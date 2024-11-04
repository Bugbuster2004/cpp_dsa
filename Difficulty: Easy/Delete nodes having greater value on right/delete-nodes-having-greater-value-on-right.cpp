//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
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
  
  Node* reverse( Node* root){
      Node* prev = NULL;
      Node* curr = root;
      while(curr){
          Node* next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      }
      return prev;
      
  }
    Node *compute(Node *head) {
        // your code goes here
        head = reverse(head);
        Node* curr = head;
        int ma = head-> data;
        Node* prev = head;
        head = head-> next;
        
        while(head){
            if(head->data>=ma){
                ma= head->data;
                prev = head;
                head= head->next;
            }else{
                prev->next = head->next;
                head = prev -> next;
            }
        }
        
        head = reverse(curr);
        return head;
        
        
        
        
        
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
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
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends