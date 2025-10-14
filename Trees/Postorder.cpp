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

void iterative_postorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    vector<int> postorder;

    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        postorder.push_back(curr->data);

        // Push left first so right is processed before left
        if (curr->left)
            st.push(curr->left);
        if (curr->right)
            st.push(curr->right);
    }

    // Reverse to get Left -> Right -> Root
    reverse(postorder.begin(), postorder.end());

    // Print the traversal
    for (int val : postorder)
        cout << val << " ";
}

// Preorder traversal
void Postorder(Node *node)
{
    if (node == NULL)
        return;

    Postorder(node->left);
    Postorder(node->right);

    cout << node->data << " ";
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
    Postorder(root);
    cout << endl;
    cout << "Inorder traversal iterative: ";
    iterative_postorder(root);

    return 0;
}
