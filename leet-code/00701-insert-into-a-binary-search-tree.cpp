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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *t = root;
        while (1) {
            if (val < t->val) {
                if (t->left == NULL) {
                    t->left = new TreeNode(val);
                    return root;
                }
                t = t->left;
            } else {
                if (t->right == NULL) {
                    t->right = new TreeNode(val);
                    return root;
                }
                t = t->right;
            }
        }
    }
};