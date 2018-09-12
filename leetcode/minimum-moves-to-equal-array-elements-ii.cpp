//
//  minimum-moves-to-equal-array-elements-ii
//  https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 让首尾对称位置的元素相遇
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0, j = (int)nums.size() - 1; i < j; i++, j--) {
            count += nums[j] - nums[i];
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
