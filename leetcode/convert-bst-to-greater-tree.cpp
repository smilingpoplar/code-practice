//
//  beautiful-arrangement
//  https://leetcode.com/problems/beautiful-arrangement/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
    
    void reverseInorder(TreeNode *root, int &sum) {
        if (!root) return;
        reverseInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left, sum);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
