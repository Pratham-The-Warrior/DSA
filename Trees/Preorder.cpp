/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

// Define the node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Iterative Preorder Traversal
vector<int> iterative_preorder(Node *root)
{
    vector<int> preorder;
    if (root == NULL)
        return preorder;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        preorder.push_back(curr->data);

        // Push right first so left is processed first
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }

    return preorder;
}

// Recursive Preorder Traversal (for comparison)
void preorder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Example usage
int main()
{
    // Create a simple binary tree for testing
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Recursive Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Iterative Preorder Traversal: ";
    vector<int> result = iterative_preorder(root);
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
