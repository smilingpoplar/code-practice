//
//  delete-node-in-a-bst
//  https://leetcode.com/problems/delete-node-in-a-bst/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->right) {
                auto left = root->left;
                delete root;
                return left;
            }
            // 把后继节点作为新根
            auto curr = root->right;
            while (curr->left) curr = curr->left;
            swap(root->val, curr->val);
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}