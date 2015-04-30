//
//  minimum-depth-of-binary-tree.cpp
//  https://leetcode.com/problems/minimum-depth-of-binary-tree/
//
//  Created by smilingpoplar on 15/4/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(0);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t1r(1);
    t0.right = &t1r;
    TreeNode t2r(2);
    t1r.right = &t2r;
    
    Solution solution;
    cout << solution.minDepth(&t0);

    return 0;
}
