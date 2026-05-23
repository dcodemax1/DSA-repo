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

 // Morris Traversal concept TC - O(N), SC - O(1)
 
class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left != NULL) {
                TreeNode* prev = NULL;

                prev = curr->left;

                while (prev->right != NULL) {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        
        curr = curr->right;
    }
  }
};


/*
 // PreOrder using stack and flatten TC - O(N), SC - O(N)

class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;

        if (root == NULL)
            return;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if (curr->right) {
                st.push(curr->right);
            }
            if (curr->left) {
                st.push(curr->left);
            }

            if (!st.empty()) {
                curr->right = st.top();
                curr->left = NULL;
            }
        }
    }
};

*/

/*
 // Brute Force Recursive Approach TC - O(N) , SC- O(N)
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {

        TreeNode* node = root;

        if (node == NULL)
            return;

        flatten(node->right);
        flatten(node->left);

        node->right = prev;
        node->left = NULL;
        prev = node;
    }
};

*/