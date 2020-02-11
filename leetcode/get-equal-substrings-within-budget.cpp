//
//  get-equal-substrings-within-budget
//  https://leetcode.com/problems/get-equal-substrings-within-budget/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int N = s.size();
        int ans = 0;
        for (int lo = 0, hi = 0, cost = 0; hi < N; hi++) {
            cost += abs(s[hi] - t[hi]);
            while (cost > maxCost) {
                cost -= abs(s[lo] - t[lo]);
                lo++;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
