//
//  binary-tree-level-order-traversal
//  https://leetcode.com/problems/binary-tree-level-order-traversal/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<int> row;
            for (int sz = q.size(); sz > 0; sz--) {
                auto node = q.front(); q.pop();
                row.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode *> curr;
        if (root) curr.push_back(root);
        while (!curr.empty()) {
            vector<int> row;
            vector<TreeNode *> next;
            for (auto node : curr) {
                row.push_back(node->val);
                
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            ans.push_back(row);
            swap(curr, next);
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(9);
    t0.left = &t1l;
    TreeNode t1r(20);
    t0.right = &t1r;
    TreeNode t2l(15);
    t1r.left = &t2l;
    TreeNode t2r(7);
    t1r.right = &t2r;
    
    Solution solution;
    auto ans = solution.levelOrder(&t0);
    for (auto &row : ans) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
