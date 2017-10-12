//
//  longest-univalue-path
//  https://leetcode.com/problems/longest-univalue-path/
//
//  Created by smilingpoplar on 15/6/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        arrowLength(root, result);
        return result;
    }
    
    int arrowLength(TreeNode *root, int &result) {
        if (!root) return 0;
        int left = arrowLength(root->left, result);
        int right = arrowLength(root->right, result);
        if (root->left && root->left->val == root->val) {
            left += 1;
        } else {
            left = 0;
        }
        if (root->right && root->right->val == root->val) {
            right += 1;
        } else {
            right = 0;
        }
        result = max(result, left + right);
        return max(left, right);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
