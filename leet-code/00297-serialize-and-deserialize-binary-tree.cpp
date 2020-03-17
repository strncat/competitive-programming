//
//  main.cpp
//  x
//
//  Created by FB on 2/4/20.
//  Copyright © 2020 FB. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (root == NULL) {
        return "null";
    } else {
        return std::to_string(root->val) +
        "," + serialize(root->left) +
        "," + serialize(root->right);
    }
}

// Decodes your encoded data to tree.
TreeNode* deserialize_helper(std::queue<string>& pre) {
    if (pre.empty()) { return NULL; }

    if (pre.front() == "null") {
        pre.pop();
        return NULL;
    }

    TreeNode *node = new TreeNode(stoi(pre.front()));
    pre.pop();
    node->left = deserialize_helper(pre);
    node->right = deserialize_helper(pre);
    return node;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.size() == 0) { return NULL; }
    std::queue<string> pre;

    // parsing shit
    size_t pos = 0;
    std::string token;
    std::string delimiter = ",";
    while ((pos = data.find(delimiter)) != std::string::npos) {
        token = data.substr(0, pos);
        pre.push(token);
        data.erase(0, pos + delimiter.length());
    }
    return deserialize_helper(pre);
}

void pre_order(TreeNode *root) {
    if (root == NULL) { return; }
    printf("%d  ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}

int main(int argc, const char * argv[]) {
    // Example 1
    // [10,5,-3,3,2,null,11,3,-2,null,1]
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    //root->left->left->left = new TreeNode(3);
    //root->left->left->right = new TreeNode(-2);

    //root->left->right->right = new TreeNode(1);

    pre_order(root);
    cout << endl;
    string result = serialize(root);
    cout << result << endl;
    TreeNode *new_root = deserialize(result);
    pre_order(new_root);
    cout << endl;
    return 0;
}
