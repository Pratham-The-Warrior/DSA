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
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> preInPostTraversal(Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return {pre, in, post};

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }

    return {pre, in, post};
}

int main()
{
    cout << "Enter tree nodes in level order (-1 for NULL):\n";
    int val;
    cin >> val;
    if (val == -1)
        return 0;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1)
        {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
        if (rightVal != -1)
        {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    vector<vector<int>> res = preInPostTraversal(root);

    for (int x : res[0])
        cout << x << " "; // Preorder
    cout << "\n";
    for (int x : res[1])
        cout << x << " "; // Inorder
    cout << "\n";
    for (int x : res[2])
        cout << x << " "; // Postorder
    cout << "\n";
}
