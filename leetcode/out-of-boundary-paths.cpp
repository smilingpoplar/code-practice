//
//  out-of-boundary-paths
//  https://leetcode.com/problems/out-of-boundary-paths/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        // 设dp[k][r][c]表示从位置[r,c]至多k步能走出边界的方式数
        // dp[k][r][c] = dp[k-1][r-1][c] + dp[k-1][r+1][c] 
        //              + dp[k-1][r][c-1] + dp[k-1][r][c+1]
        // 初始dp[0][][]=0；注意四个边界的dp值为1
        // 递推式第k项只依赖第k-1项，省掉k这维，用临时变量ndp
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int k = 1; k <= N; k++) {
            vector<vector<int>> ndp(m, vector<int>(n, 0));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    long paths = r == 0 ? 1 : dp[r-1][c];
                    paths += r == m - 1 ? 1 : dp[r+1][c];
                    paths += c == 0 ? 1 : dp[r][c-1];
                    paths += c == n - 1 ? 1 : dp[r][c+1];
                    ndp[r][c] = paths % MOD;                    
                }
            }
            swap(dp, ndp);            
        }
        return dp[i][j];        
    }
};

/*
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return findPaths(m, n, N, i, j, memo);        
    }
    
    // 从位置[i,j]至多N步能走出边界的方式数
    int findPaths(int m, int n, int N, int i, int j, vector<vector<vector<int>>> &memo) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (N == 0) return 0;
        
        if (memo[N][i][j] != -1) return memo[N][i][j];
        const int MOD = 1e9 + 7;
        int ans = findPaths(m, n, N - 1, i - 1, j, memo);
        ans = (ans + findPaths(m, n, N - 1, i + 1, j, memo)) % MOD;
        ans = (ans + findPaths(m, n, N - 1, i, j - 1, memo)) % MOD;
        ans = (ans + findPaths(m, n, N - 1, i, j + 1, memo)) % MOD;
        memo[N][i][j] = ans;
        return ans;        
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
