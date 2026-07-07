//========================================//
// Variation of Leetcode 138 , 117
//========================================//

// class Solution {
// private:
//     unordered_map<Node*, Node*> mp;

//     Node* getClone(Node* node) {
//         if (!node) return nullptr;
//         if (mp.find(node) == mp.end()) {
//             mp[node] = new Node(node->val);
//         }
//         return mp[node];
//     }

// public:
//     Node* cloneNaryTree(Node* root) {
//         if (!root) return nullptr;

//         Node* clonedCurr = getClone(root);

//*         // Map the parent pointer
//         if (root->parent) {
//             clonedCurr->parent = getClone(root->parent);
//         }

//*         // Map all children pointers and recurse
//         for (Node* child : root->children) {
//             if (child) {
//                 clonedCurr->children.push_back(getClone(child));

//*                 // Recursively clone the child's subtree
//                 cloneNaryTree(child);
//             }
//         }

//         return clonedCurr;
//     }
// };
