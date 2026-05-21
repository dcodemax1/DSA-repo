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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> node;
        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* nodes = p.first;
            int x = p.second.first;
            int y = p.second.second;

            node[x][y].insert(nodes->val);

            if (nodes->left != NULL) {
                todo.push({nodes->left, {x - 1, y + 1}});
            }

            if (nodes->right != NULL) {
                todo.push({nodes->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;

        for (auto p : node) {
            vector<int> col;

            for (auto q : p.second) {

                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};