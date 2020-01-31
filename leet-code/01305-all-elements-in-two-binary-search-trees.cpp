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
    int h[300000] = {0};

    void in_order(TreeNode * root) {
        if (root == NULL) {
            return;
        }
        if (root->val < 0) {
            h[(-1*root->val) + 100001]++;
        } else {
            h[root->val]++;
        }
        in_order(root->left);
        in_order(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        in_order(root1);
        in_order(root2);
         vector<int> elements;
        for (int i = 200005; i >= 100001; i--) {
            while (h[i]) {
                elements.push_back(-1*(i-100001));
                h[i]--;
            }
        }
        for (int i = 0; i < 100001; i++) {
            while (h[i]) {
                elements.push_back(i);
                h[i]--;
            }
        }
        return elements;
    }
};