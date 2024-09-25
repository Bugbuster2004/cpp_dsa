//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



// } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
    /*You are required to complete below method */
    int evalTree(node* root) {
        // Base case: if the node is NULL, return 0 (though this case should not occur)
        if(root == NULL) {
            return 0;
        }

        // If it's a leaf node (contains an integer), return the integer value
        if(root->left == NULL && root->right == NULL) {
            return stoi(root->data);  // Converting the string data to integer
        }

        // Recursively evaluate the left and right subtrees
        int leftVal = evalTree(root->left);
        int rightVal = evalTree(root->right);

        // Perform the operation based on the operator in the current node
        if(root->data == "+") {
            return leftVal + rightVal;
        }
        else if(root->data == "-") {
            return leftVal - rightVal;
        }
        else if(root->data == "*") {
            return leftVal * rightVal;
        }
        else if(root->data == "/") {
            return leftVal / rightVal;
        }

        // If none of the above cases, return 0 (this shouldn't normally happen)
        return 0;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}

// } Driver Code Ends