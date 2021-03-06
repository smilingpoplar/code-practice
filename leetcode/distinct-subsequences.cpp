//
//  distinct-subsequences
//  https://leetcode.com/problems/distinct-subsequences/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // 设dp[i][j]表示s[i..]子序列等于t[j..]的个数 (0<=i<=M, 0<=j<=N）
        // 若s[i]==t[j]，dp[i][j] = dp[i+1][j+1]/*使用s[i]*/ + dp[i+1][j]/*不用s[i]*/
        // 若s[i]!=t[j]，dp[i][j] = dp[i+1][j]
        // 初值：dp[i][N]=1，dp[M][j<N]=0
        // 省略i这一维，i仍从右向左遍历，要让dp[j+1]是旧状态，j从左向右遍历
        const int M = s.size(), N = t.size();
        vector<int> dp(N + 1, 0); // 对应i==M
        dp[N] = 1;

        for (int i = M; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (s[i] == t[j]) {
                    dp[j] += dp[j+1];
                }
            }
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.numDistinct("rabbbit", "rabbit");
    
    return 0;
}
