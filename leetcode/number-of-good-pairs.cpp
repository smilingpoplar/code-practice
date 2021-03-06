//
//  number-of-good-pairs
//  https://leetcode.com/problems/number-of-good-pairs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt; // num=>count
        int ans = 0;
        for (int num : nums) {
            if (cnt.count(num)) {
                ans += cnt[num];
            }
            cnt[num]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
