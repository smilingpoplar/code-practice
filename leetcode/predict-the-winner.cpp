//
//  predict-the-winner
//  https://leetcode.com/problems/predict-the-winner/
//
//  Created by smilingpoplar on 17/11/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // 设dp[i][j]表示当前玩家从nums[i..j]局面能得的最高分
        // dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])，0<=i<=j<N
        // 初始j==i时，dp[i][i]=nums[i]
        const int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) dp[i][i] = nums[i];
        // 递推式在i维上从右往左遍历、在j维上从左往右遍历
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][N-1] >= 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
