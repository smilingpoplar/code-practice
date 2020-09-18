//
//  sum-of-mutated-array-closest-to-target
//  https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        const int N = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> presum(N + 1, 0); // presum[i]表示sum(arr[0..i))
        int mx = INT_MIN;
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + arr[i];
            mx = max(mx, arr[i]);
        }
        
        int l = 0, u = mx + 1;
        while (l + 1 < u) {
            int m = l + (u - l) / 2;
            // 数组之和sum(value)是关于value的递增函数，
            // sum(value)>=target满足二分搜索的条件形式[0..0 1..1]
            if (getSum(m, arr, presum) >= target) {
                u = m;
            } else {
                l = m;
            }
        }
        // 找最接近target的数，u和u-1作为候选
        int diff1 = abs(getSum(u, arr, presum) - target);
        int diff2 = abs(getSum(u-1, arr, presum) - target);
        return diff2 <= diff1 ? u-1 : u;
    }
    
    int getSum(int value, vector<int>& arr, const vector<int> &presum) {
        // 将>=value的值全变成value
        int idx = lower_bound(arr.begin(), arr.end(), value) - arr.begin();
        // [0..idx)为原数，[idx..N)变为value
        int sum = presum[idx] + (arr.size() - idx) * value;
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
