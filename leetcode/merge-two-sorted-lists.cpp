//
//  merge-two-sorted-lists
//  https://leetcode.com/problems/merge-two-sorted-lists/
//
//  Created by smilingpoplar on 15/5/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        auto p = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    l1.next = &l3;
    l3.next = &l5;
    l2.next = &l4;
    l4.next = &l6;
    
    Solution solution;
    auto head = solution.mergeTwoLists(&l1, &l2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
