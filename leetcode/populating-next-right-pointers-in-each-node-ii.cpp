//
//  populating-next-right-pointers-in-each-node-ii
//  https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
//
//  Created by smilingpoplar on 15/6/6.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy(0); // 下层起点
        auto prev = &dummy;
        while (root) { // 遍历当前层，当前层已用next指针连接
            if (root->left) {
                prev->next = root->left;
                prev = root->left;
            }
            if (root->right) {
                prev->next = root->right;
                prev = root->right;
            }
            root = root->next;

            if (!root) { 
                root = dummy.next;
                dummy.next = NULL;
                prev = &dummy;
            }
        }
    }
};

void print(TreeLinkNode *root) {
    while (root) { // 遍历当前层
        TreeLinkNode *leftMost = NULL; // 下一层的leftMost节点
        for (auto current = root; current; current = current->next) {
            cout << current->val << " ";
            if (!leftMost) leftMost = current->left ? current->left : current->right;
        }
        cout << endl;
        root = leftMost;
    }
}

int main(int argc, const char * argv[]) {
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    TreeLinkNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    
    Solution solution;
    solution.connect(&n1);
    print(&n1);
    
    return 0;
}
