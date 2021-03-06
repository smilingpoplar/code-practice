//
//  linked-list-cycle-ii
//  https://leetcode.com/problems/linked-list-cycle-ii/
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针，fast跑两步slow跑一步，slow进入环后不到一圈肯定被fast追上，
        // 假设从链表头到环起点的距离为a，从环起点到环中相遇点的距离为b，
        // 有 a+b+n*L = 2(a+b), a = n*L-b
        // 即 若两指针从链表头和环中相遇点同速跑，将在环入口相遇。
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { // 相遇，再同速跑
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
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
    l5.next = &l3;
    
    Solution solution;
    auto node = solution.detectCycle(&l1);
    if (node) cout << node->val;
    else cout << "NULL";
    
    return 0;
}
