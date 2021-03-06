//
//  missing-number
//  https://leetcode.com/problems/missing-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        const int N = nums.size();
        int x = 0;
        for (int i = 0; i <= N; i++) x ^= i;
        for (auto num : nums) x ^= num;
        return x;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,3};
    Solution solution;
    cout << solution.missingNumber(nums);
    
    return 0;
}
