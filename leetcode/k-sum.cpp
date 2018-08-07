//
//  k-sum
//  https://lintcode.com/problems/k-sum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kSum(vector<int> &A, int K, int target) {
        // 设dp[i][k][t]表示A[0..i-1]中选k个数，它们的和为t的方式数
        // dp[i][k][t] = dp[i-1][k][t] /*不选A[i-1]*/ + dp[i-1][k-1][t - A[i-1]] /*选A[i-1]*/
        // 0<=i<=N，1<=k<=K，0<=t<=target
        // 初始dp[i][0][0] = 1
        // 递推式在i这维上只依赖于i-1项，可省掉i这维，i仍从左往右遍历
        // k这维上dp[][k-1][]要表示旧状态，k从右往左遍历；同理，t从右往左遍历
        const int N = A.size();
        vector<vector<int>> dp(K + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int k = min(i,K); k >= 1; k--) {
                for (int t = target; t >= 0; t--) {
                    if (t >= A[i-1]) dp[k][t] += dp[k-1][t - A[i-1]];
                }
            }
        }
        return dp[K][target];
    }
};

/*
class Solution {
public:
    int kSum(vector<int> &A, int K, int target) {
        // 设dp[i][k][t]表示A[0..i-1]中选k个数，它们的和为t的方式数
        // dp[i][k][t] = dp[i-1][k][t] /*不选A[i-1]*/ + dp[i-1][k-1][t - A[i-1]] /*选A[i-1]*/
        // 0<=i<=N，1<=k<=K，0<=t<=target
        // 初始dp[i][0][0] = 1
        const int N = A.size();
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(target + 1, 0)));
        for (int i = 0; i <= N; i++) {
            dp[i][0][0] = 1;  
        }

        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= min(i,K); k++) {
                for (int t = 0; t <= target; t++) {
                    dp[i][k][t] += dp[i-1][k][t];
                    if (t >= A[i-1]) dp[i][k][t] += dp[i-1][k-1][t - A[i-1]];
                }
            }
        }
        return dp[N][K][target];
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}