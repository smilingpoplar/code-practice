//
//  reverse-nodes-in-k-group
//  https://leetcode.com/problems/reverse-nodes-in-k-group/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        for (auto node = head; node && len < k; node = node->next) len++;
        if (len < k) return head;
        // 反转前k个
        ListNode *list = NULL;
        auto node = head;
        for (int i = 0; i < k; i++) {
            auto next = node->next;
            node->next = list;
            list = node;
            node = next;
        }
        // 至此head是组内尾元素，node是下一组头元素
        head->next = reverseKGroup(node, k);
        return list;
    }
};
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        for (auto p = head; p; p = p->next) len++;

        ListNode dummy(-1);
        dummy.next = head;
        auto prev = &dummy; // 组前的指针

        for (; len >= k; len -= k) {
            // 组头是反转后的组为tail，将组内第[2..k]元素插入到prev之后
            auto tail = prev->next, curr = tail->next;
            for (int i = 2; i <= k; i++) {
                tail->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
                curr = tail->next;
            }
            prev = tail;
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    
    Solution solution;
    auto head = solution.reverseKGroup(&l1, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
