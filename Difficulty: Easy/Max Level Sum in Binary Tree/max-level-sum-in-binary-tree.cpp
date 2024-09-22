//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}



// } Driver Code Ends
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
public:
    int maxLevelSum(Node* root) {
        // If the tree is empty, return 0
        if (root == NULL) {        // Fix 1: Add return 0
            return 0;
        }
        
        // Initialize queue for level order traversal
        queue<Node*> q;
        q.push(root);

        int maxSum = INT_MIN;      // Fix 2: Track maximum level sum
                                   // Fix 5: No need for vector<int>

        // Perform BFS
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level
            int levelSum = 0;  // Fix 3: Reset sum for the current level

            // Process each node of the current level
            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();

                // Add the node's value to the current level's sum
                levelSum += node->data;

                // Enqueue left child if exists
                if (node->left != NULL) {
                    q.push(node->left);
                }

                // Enqueue right child if exists
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // Fix 4: Update maxSum if the current level sum is greater
            maxSum = max(maxSum, levelSum);
        }

        return maxSum;  // Fix 6: Return the maximum sum
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution obj;
        Node *root = buildTree(treeString);
        cout << obj.maxLevelSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends