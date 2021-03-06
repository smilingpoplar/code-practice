//
//  single-number-iii
//  https://leetcode.com/problems/single-number-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 设x和y是数组中只出现1次的两个数
        int xXorY = 0;
        for (auto num : nums) {
            xXorY ^= num;
        }
        // xXorY中任意一位1表示x和y该处不同，不妨取最后一位1来区分x和y
        int lastOne = xXorY & -xXorY;
        int x = 0;
        for (auto num : nums) {
            if (num & lastOne) x ^= num;
        }
        int y = x ^ xXorY;
        
        return {x, y};
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    Solution solution;
    auto result = solution.singleNumber(nums);
    for (auto num : result) {
        cout << num << " ";
    }
    
    return 0;
}
