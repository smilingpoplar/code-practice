//
//  closest-binary-search-tree-value-ii
//  https://leetcode.com/problems/closest-binary-search-tree-value-ii/
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // 前驱栈pre和后继栈succ
        stack<TreeNode *> pre, succ;
        auto p = root;
        while (p) {
            if (target < p->val) {
                succ.push(p);
                p = p->left;
            } else {
                pre.push(p);
                p = p->right;
            }
        }
        
        vector<int> ans;
        while (k--) {
            // 往两端的两指针
            if (succ.empty() || (!pre.empty() && target - pre.top()->val < succ.top()->val - target)) { // 选前驱
                ans.push_back(pre.top()->val);
                getPredecessor(pre);
            } else {
                ans.push_back(succ.top()->val);
                getSuccessor(succ);
            }
        }
        return ans;
    }
    
    // 类似i--，一路进栈到左子树的最右值
    void getPredecessor(stack<TreeNode *> &pre) {
        auto top = pre.top(); pre.pop();
        auto p = top->left;
        while (p) {
            pre.push(p);
            p = p->right;
        }
    }
    
    // 类似j++，一路进栈到右子树最左值
    void getSuccessor(stack<TreeNode *> &succ) {
        auto top = succ.top(); succ.pop();
        auto p = top->right;
        while (p) {
            succ.push(p);
            p = p->left;
        }
    }
};

/*
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> q;
        inorder(root, target, k, q);
        return vector<int>(q.begin(), q.end());
    }
    
    void inorder(TreeNode *root, double target, int k, deque<int> &q) {
        if (!root) return;
        // 用中序遍历和k长队列
        inorder(root->left, target, k, q);
        if (q.size() < k) {
            q.push_back(root->val);
        } else if (abs(root->val - target) < abs(q.front() - target)) {
                q.pop_front();
                q.push_back(root->val);
        } else return;
        inorder(root->right, target, k, q);
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
