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

 // Iterative Traversal using 1 stack 
 
class Solution {
public:
    void findPostOrder(TreeNode* root, vector<int>& postOrder) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;

                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();

                        postOrder.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;

        findPostOrder(root, postOrder);

        return postOrder;
    }
};

/*
 // Iterative Approach using 2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == NULL)
            return postOrder;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);

        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left != NULL)
                st1.push(root->left);
            if (root->right != NULL)
                st1.push(root->right);

        }
        while (!st2.empty()) {
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }
};
*/

/*
// recusrive traversal approach

class Solution {
public:
    void findpostOrder(TreeNode* root, vector<int>& res) {
        if (root == NULL)
            return;

        findpostOrder(root->left, res);
        findpostOrder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        findpostOrder(root, res);
        return res;
    }
};
*/