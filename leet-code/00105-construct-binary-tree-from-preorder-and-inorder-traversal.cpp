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
    unordered_map<int,int> inorder_map;

TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                 int in_start, int in_end,
                 int pre_start, int pre_end) {
    if (pre_start >= pre_end || in_start >= in_end) { return NULL; }

    TreeNode *root = new TreeNode(preorder[pre_start]);

    // split the inorder array around the pivot
    int mid = inorder_map[root->val];

    int left_size = mid - in_start;

    root->left = helper(preorder, inorder,
                        in_start, mid,
                        pre_start+1, pre_start+left_size+1);

    root->right = helper(preorder, inorder,
                         mid+1, in_end,
                         pre_start+left_size+1, pre_end);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) { return NULL; }

    // ONLY BECAUSE NO DUPS, otherwise what? linear search?
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
        inorder_map[inorder[i]] = i;
    }
    return helper(preorder, inorder, 0, n, 0, n);
}
};