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
class Solution {
public:
    TreeNode* makeTree(vector<int>& preorder, int ps, int preEnd,
                       vector<int>& inorder, int is, int inend,
                       map<int, int>& i_map) {

        if (ps > preEnd || is > inend)
            return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int in_root = i_map[root->val];

        int numsLeft = in_root - is;

        root->left = makeTree(preorder, ps + 1, ps + numsLeft + 1, inorder, is,
                              in_root - 1, i_map);

        root->right = makeTree(preorder, ps + numsLeft + 1, preEnd, inorder,
                               in_root + 1, inend, i_map);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> i_map;
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            i_map[inorder[i]] = i;
        }

        TreeNode* root = makeTree(preorder, 0, preorder.size() - 1, inorder, 0,
                                  inorder.size() - 1, i_map);

        return root;
    }
};