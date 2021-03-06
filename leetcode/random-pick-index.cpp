//
//  random-pick-index
//  https://leetcode.com/problems/random-pick-index/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) : nums(nums) {
        srand(time(NULL));
    }
    
    int pick(int target) {        
        int ans = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            count++;
            // 以1/count概率替换掉已选
            if (rand() % count == 0) ans = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
