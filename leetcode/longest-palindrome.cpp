//
//  longest-palindrome
//  https://leetcode.com/problems/longest-palindrome/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        for (char c : s)
            count[c]++;
        
        int ans = 0;
        for (auto &e : count)
            ans += e.second / 2 * 2;
        if (ans < s.size()) ans++;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
