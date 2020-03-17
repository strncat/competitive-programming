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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int first, int last) {
        if (first > last) { return NULL; }
        // make a node
        int mid = first + (last - first) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(nums, first, mid-1);
        node->right = helper(nums, mid+1, last);
        return node;
    }
};