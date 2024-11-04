//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
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
// User function template for C++

/*
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
    Node* divide(Node* head) {
        // code here
        
        Node* even = NULL;
        Node* odd = NULL;
        Node* e = NULL;
        Node* o = NULL;
        
        while(head){
            if(head->data%2==0){
                if(even == NULL){
                    even = head;
                    e = head;
                }else{
                    e ->next = head;
                    e = e->next;
                }
            }else{
                if(odd == NULL){
                    odd = head;
                    o = head;
                }else{
                    o->next = head;
                    o = o->next;
                }
            }
            head= head -> next;
        }
        
        if(e) e->next  = odd;
        if(o) o -> next = NULL;
        if(even)  return even;
        return odd;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends