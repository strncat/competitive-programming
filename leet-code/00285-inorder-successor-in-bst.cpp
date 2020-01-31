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
            // if we arrived at p then we have two cases
            // case 1: p has a right subtree and so the successor is 
            // the left most node in that subtree
            // case 2: we already have seen the successor in a previous 
            // iteration of this loop so we return previous
            if (t == p) {
                if (t->right) { // case 1
                    return leftMostNode(t->right);
                } else { // case 2
                    return prev;
                }
            }

            // if we're not at p yet then we have two cases:
            // case 1: p is in the left subtree, in this case t
            // could still be a potenial successor
            // case 2: p is in the right subtree, in this case,
            // t couldn't be a potenial successor because p has a higher value
            // in an order traversal, we've seen t already
            if (p->val < t->val) {
                prev = t;
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return NULL;
    }
};