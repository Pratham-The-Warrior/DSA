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

// Function to perform Level Order Traversal and return result as vector of vectors
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result; // edge case

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();

            level.push_back(current->data);

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        result.push_back(level);
    }

    return result;
}

// Example usage
int main()
{
    // Create a simple binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> levels = levelOrder(root);

    cout << "Level Order Traversal (by levels):\n";
    for (auto &level : levels)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
