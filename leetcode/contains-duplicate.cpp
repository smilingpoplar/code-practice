//
//  contains-duplicate
//  https://leetcode.com/problems/contains-duplicate/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            if (st.count(num)) return true;
            st.insert(num);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,1,2,4};
    Solution solution;
    cout << solution.containsDuplicate(nums);
    
    return 0;
}
