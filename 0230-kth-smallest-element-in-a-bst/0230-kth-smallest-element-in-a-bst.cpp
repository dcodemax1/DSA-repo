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
    void findInorder(TreeNode* root, int k, int& kthSmall, int& counter) {

        if (!root || counter >= k)
            return;

        findInorder(root->left, k, kthSmall, counter);
            counter++;

            if (counter == k) {
                kthSmall = root -> val;
                return;
            }
        
        findInorder(root->right, k, kthSmall, counter);
    }

    int kthSmallest(TreeNode* root, int k) {
        int kthSmall = INT_MIN;
        int counter = 0;

        findInorder(root, k, kthSmall, counter);

        return kthSmall;
    }
};