//
//  main.cpp
//  nim
//
//  Created by FB on 1/25/20.
//  Copyright © 2020 FB. All rights reserved.
//

#include <iostream>
#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode *root) {
    if (root == NULL) { return 0; }
    int d = 0;

    while (root && root->left != NULL) {
        root = root->left;
        d++;
    }
    return d;
}

bool exists(TreeNode* root, int x, int d) {
    int left = 0;
    int right = std::pow(2,d) - 1;
    // find that leaf x
    // there are d levels in the tree
    // we need to go down all the way to level d
    for (int i = 0; i < d; i++) {
        // at each level we determine which direction we take
        int mid = left + (right - left) / 2;
        if (x <= mid) {
            // go left
            root = root->left;
            right = mid - 1;
        } else {
            root = root->right;
            left = mid + 1;
        }
    }
    // we are at that node
    return root != NULL;
}

int countNodes(TreeNode* root) {
    if (root == NULL) { return 0; }
    int d = depth(root);

    // at level 0 we have 2^0 = 1 node
    // at level 1 we have 2^1 = 2 nodes
    // at level d we have 2^d nodes
    // sum all levels
    // number of nodes = 1 + 2 + 4 + ... + 2^d = 2^{d+1} - 1

    // if we exclude the last level then
    // the sum up to level d-1 is 2^{d} - 1
    // we need to deal with the last level seperately
    // since it might not have all of the 2^d nodes

    // we know the nodes are as far left as possible
    // so find that point where there are no nodes anymore
    // we have 0 to 2^d-1 possible children
    // use binary search!

    int left = 0;
    int right = std::pow(2,d) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (exists(root, mid, d)) {
            // forget the left half
            left = mid + 1;
        } else {
            // child doesn't exist, we need to focus on the left half
            right = mid - 1;
        }
    }

    return std::pow(2,d) - 1 + left;
}

int main() {
    TreeNode root = TreeNode(1);
    TreeNode child2 = TreeNode(2);
    TreeNode child3 = TreeNode(3);
    root.left = &child2;
    root.right = &child3;
    TreeNode child4 = TreeNode(4);
    TreeNode child5 = TreeNode(5);
    child2.left = &child4;
    child2.right = &child5;
    TreeNode child6 = TreeNode(6);
    child3.left = &child6;
    printf("%d\n", countNodes(&root));
}
