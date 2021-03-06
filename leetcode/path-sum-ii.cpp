//
//  path-sum-ii
//  https://leetcode.com/problems/path-sum-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        searchFrom(root, sum, path, ans);
        return ans;
    }
    
    void searchFrom(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &ans) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (root->val == sum) ans.push_back(path);
        } else {
            if (root->left) searchFrom(root->left, sum - root->val, path, ans);
            if (root->right) searchFrom(root->right, sum - root->val, path, ans);
        }
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(5);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t1r(8);
    t0.right = &t1r;
    
    Solution solution;
    auto allPaths = solution.pathSum(&t0, 13);
    for (const auto &path : allPaths) {
        for (int n : path) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}
