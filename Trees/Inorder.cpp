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
};

void iterative_inorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty())
    {
        // 1️⃣ Go as left as possible
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        // 2️⃣ Process the node at the top
        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // 3️⃣ Move to the right subtree
        curr = curr->right;
    }
}

// Preorder traversal
void Inorder(Node *node)
{
    if (node == NULL)
        return;

    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

// Example usage
int main()
{
    // Create a simple binary tree for testing
    Node *root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};

    cout << "Inorder traversal: ";
    Inorder(root);
    cout << endl;

    return 0;
}
