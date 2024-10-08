//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isCousins(Node* root, int x, int y);

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        if (x == y) {
            cout << "0\n";
            continue;
        }
        cout << isCousins(root, x, y) << endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
bool isCousins(Node *root, int a, int b) {
    if (!root) return false;  // If the tree is empty

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        bool foundA = false, foundB = false;

        // Process each level
        for (int i = 0; i < n; ++i) {
            Node *temp = q.front();
            q.pop();

            // Check if the current node has children that are 'a' and 'b'
            if (temp->left && temp->right) {
                if ((temp->left->data == a && temp->right->data == b) ||
                    (temp->left->data == b && temp->right->data == a)) {
                    // 'a' and 'b' are siblings, so they cannot be cousins
                    return false;
                }
            }

            // Mark found 'a' and 'b'
            if (temp->data == a) foundA = true;
            if (temp->data == b) foundB = true;

            // Push the children of the current node into the queue for the next level
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        // If both 'a' and 'b' are found at the same level, they are cousins
        if (foundA && foundB) return true;

        // If one of them is found but the other isn't, they cannot be cousins
        if (foundA || foundB) return false;
    }

    return false;  // In case 'a' or 'b' is not found in the tree
}

     
