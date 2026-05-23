/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Morris Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;

        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                pre.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    pre.push_back(curr->val);
                    curr = curr->left;
                }

                else {
                    prev->right = NULL;

                    curr = curr->right;
                }
            }
        }
        return pre;
    }
};
/*
// Iterative Solution

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;

        if (root == NULL)
            return pre;
        stack<TreeNode*> st;

        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();

            pre.push_back(root->val);
            if (root->right != NULL)
                st.push(root->right);
            if (root->left != NULL)
                st.push(root->left);
        }
        return pre;
    }
};

*/

/* Brute Force Recursive Approach

class Solution {
public:
    void findPreOrder(TreeNode* root, vector<int>& pre){

    if (root == NULL)
        return;

    pre.push_back(root->val);
    findPreOrder(root->left, pre);
    findPreOrder(root->right, pre);

}

vector<int>
preorderTraversal(TreeNode* root) {
    vector<int> pre;

    findPreOrder(root, pre);

    return pre;
  }
};

*/
