//
//  longest-consecutive-sequence
//  https://leetcode.com/problems/longest-consecutive-sequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 把数都塞到集合中，然后取出无x-1的数x
        // 看后序的x+1,x+2,...是否也在集合中
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);
        
        int ans = 0;
        for (int num : nums) {
            if (st.count(num - 1)) continue;
            int len = 1;
            while (st.count(num + len))
                len++;
            ans = max(ans, len);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    cout << solution.longestConsecutive(nums);

    return 0;
}
