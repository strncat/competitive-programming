/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// credits to elements of programming interviews
class Solution {
public:
    TreeNode* leftMostNode(TreeNode* root) {
        TreeNode *t = root;
        while (t->left) {
            t = t->left;
        }
        return t;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) { return NULL; }
        if (p == NULL) { return NULL; }

        TreeNode *t = root;
        TreeNode *prev = NULL;

        while (t) {
            // case 1: p is in the left subtree, in this case t could
            // still be a potenial successor, we assign prev to t
            if (t->val > p->val) {
                prev = t;
                t = t->left;
            } else {
            // case 2: p is in the right subtree, in this case,
            // t couldn't be a potenial successor because p has a higher value
            // so just move right
                t = t->right;
            }
        }
        return prev;
    }
};
