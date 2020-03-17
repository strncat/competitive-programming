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
    TreeNode* leftMost(TreeNode *root) {
        if (root == NULL) { return NULL; }
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) { return NULL; }
        
        // node is on the right
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) { // node is on the left
            root->right = deleteNode(root->right, key);
        } else {
            
            // case 1: one child is missing
            if (root->left == NULL) { // left child is missing
                return root->right;
            } else if (root->right == NULL) { // right child is missing
                return root->left;
            }

            // otherwise, we have a right child and we can replace its value 
            // with the left most child in that subtree
            TreeNode *min = leftMost(root->right);
            if (min) {
                root->val = min->val; // current node gets child's value
                root->right = deleteNode(root->right, root->val); // we delete the child instead
            }
        }
        return root;
    }
};