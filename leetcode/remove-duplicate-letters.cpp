//
//  remove-duplicate-letters
//  https://leetcode.com/problems/remove-duplicate-letters/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 要使剩余串的字典序最小<=>递增栈<=>找下一个更小的数
        // 限制条件：1.已入栈的不再选择 2.某字母有富余时才可pop()
        vector<int> cnt(128, 0); // 各字母计数
        for (char c : s) cnt[c]++;
        vector<bool> picked(128, false);

        string stk;
        for (char c : s) {
            cnt[c]--;
            if (picked[c]) continue; // 条件1
            while (!stk.empty() && c < stk.back() 
                    && cnt[stk.back()] > 0) { // 条件2
                int top = stk.back(); stk.pop_back();
                picked[top] = false;
            }
            stk.push_back(c);
            picked[c] = true;
        }
        return stk;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
