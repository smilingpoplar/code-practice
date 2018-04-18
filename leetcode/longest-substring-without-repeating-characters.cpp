//
//  longest-substring-without-repeating-characters
//  https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
//  Created by smilingpoplar on 15/5/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int start = 0, repeat = 0, ans = 0;
        for (int end = 0; end < s.size(); end++) {
            if (count[s[end]]++ > 0) repeat++;
            while (repeat > 0) {
                if (--count[s[start]] > 0) repeat--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // 用map记录滑动窗口内的char=>lastIdx
        int ans = 0;
        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            if (mp.count(s[end])) {
                start = max(start, mp[s[end]] + 1);
            }
            ans = max(ans, end - start + 1);
            mp[s[end]] = end;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abbaab");
    
    return 0;
}
