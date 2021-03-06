//
//  wiggle-sort
//  https://leetcode.com/problems/wiggle-sort/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // 从左往右，把不符合要求的相邻数对换
        for (int i = 0; i + 1 < nums.size(); i++) {
            if ((i % 2 == 0 && nums[i] > nums[i+1]) || (i % 2 == 1 && nums[i] < nums[i+1])) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
