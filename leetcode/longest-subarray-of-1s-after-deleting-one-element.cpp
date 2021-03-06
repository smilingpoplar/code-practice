//
//  longest-subarray-of-1s-after-deleting-one-element
//  https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        int zeroCnt = 0, ans = INT_MIN;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (nums[hi] == 0) zeroCnt++;
            while (zeroCnt > 1) {
                if (nums[lo++] == 0) zeroCnt--;
            }
            ans = max(ans, hi - lo); // 一定要删除一个
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
