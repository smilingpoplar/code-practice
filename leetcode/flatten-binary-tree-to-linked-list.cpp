//
//  flatten-binary-tree-to-linked-list
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // 前序遍历
        stack<TreeNode *> stk;
        if (root) stk.push(root);
        TreeNode *prev = NULL;
        while (!stk.empty()) {
            auto node = stk.top(); stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
            
            node->left = node->right = NULL;
            if (prev) prev->right = node;
            prev = node;
        }
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(1);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t2r(3);
    t1l.right = &t2r;
    
    Solution solution;
    solution.flatten(&t0);
    auto head = &t0;
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
    
    return 0;
}
