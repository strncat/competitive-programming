/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) { return vector<int>(); }
        vector<int> preorder;
        std::stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            preorder.push_back(cur->val);
            s.pop();
            
            if (cur->right) {
                s.push(cur->right);
            }

            if (cur->left) {
                s.push(cur->left);
            }
        }
        return preorder;
    }
};