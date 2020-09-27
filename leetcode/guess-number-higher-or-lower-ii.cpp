//
//  guess-number-higher-or-lower-ii
//  https://leetcode.com/problems/guess-number-higher-or-lower-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT_MAX));
        return dfs(1, n, memo);
    }

    int dfs(int lo, int hi, vector<vector<int>>& memo) {
        if (lo >= hi) return 0;
        if (memo[lo][hi] != INT_MAX) return memo[lo][hi];
        // memo[lo][hi] = min{ k + max(memo[lo][k-1], memo[k+1][hi]) }，lo<=k<=hi
        // min{expr}中expr表示猜数字i为保证赢需要多少钱，取min在所有保证赢的情况里选最少需要多少钱
        for (int k = lo; k <= hi; k++) {
            int money = k + max(dfs(lo, k - 1, memo), dfs(k + 1, hi, memo));
            memo[lo][hi] = min(memo[lo][hi], money);
        }
        return memo[lo][hi];
    }
};

/*
class Solution {
public:
    int getMoneyAmount(int n) {
        // 设dp[i][j]表示猜[i..j]数字的子问题保证赢需要多少钱，1<=i<=j<=n
        // dp[i][j] = min{ k + max(dp[i][k-1], dp[k+1][j]) }，i<=k<=j
        // 其中k+max(dp[i][k-1],dp[k+1][j])表示猜k保证赢需要多少钱，
        // dp[i][j] = min{...}表示所有保证赢的情况里最少需要多少钱。
        // 初始dp[i][i]=0
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }
        for (int i = n; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = i; k <= j; k++) {
                    int money = k + max(i <= k - 1 ? dp[i][k-1] : 0, k + 1 <= j ? dp[k+1][j] : 0);
                    dp[i][j] = min(dp[i][j], money);
                }                
            }
        }
        return dp[1][n];
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
