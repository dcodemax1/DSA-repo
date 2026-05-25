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

private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) {

            if (first == NULL) {
                first = prev;
                middle = root;
            }

            else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {

        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && last ) swap(first->val, last->val);

        else if(first && middle) swap(first->val, middle->val);
    }
};

/*
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

*/