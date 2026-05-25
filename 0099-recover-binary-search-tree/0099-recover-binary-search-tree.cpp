/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Brute Force 
 
class Solution {
public:

  void inorder(TreeNode* root, vector<int>& arr){
    if (root== NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
  }

  void  replaceValues(TreeNode* root , int& i ,vector<int>& arr ){
    if(root==NULL) return;
    replaceValues(root->left, i , arr);

    root->val = arr[i];
    i++;

    replaceValues(root->right, i , arr);

  }

    void recoverTree(TreeNode* root) {
        vector<int> arr;

        inorder(root, arr);
        sort(arr.begin(), arr.end());

        int i = 0;
        replaceValues(root, i, arr);
    }
};