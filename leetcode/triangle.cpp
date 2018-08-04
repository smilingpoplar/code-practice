//
//  triangle
//  https://leetcode.com/problems/triangle/
//
//  Created by smilingpoplar on 15/6/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // 考查到t[i][j]的路径，可来自上一行的t[i-1][j-1]或t[i-1][j]
        // 设dp[i,j]表示从t[0][0]到t[i][j]的最小路径和，则
        // dp[i,j] = min( dp[i-1,j-1], dp[i-1,j] ) + t[i][j]，0<j<i<N（不含边界j==0和j==i）
        // 当j==0时，dp[i,j] = dp[i-1,j] + t[i][j]；当j==i时，dp[i,j] = dp[i-1,j-1] + t[i][j]
        // 在i这一维上递推式只依赖于i-1项，可省略i这一维，保持i从左往右遍历
        // 要让dp[j-1]表示降维前旧值dp[i-1][j-1]，j从右往左遍历
        // dp[j] = min(dp[j-1], dp[j]) + t[i][j]
        if (triangle.empty()) return 0;
        const int N = triangle.size();
        vector<int> dp(N, 0); // 对应i==0
        dp[0] = triangle[0][0];

        for (int i = 1; i < N; i++) {
            dp[i] = dp[i-1] + triangle[i][i]; // j==i
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0]; // j==0
        }

        int ans = INT_MAX;
        for (int j = 0; j < N; j++) {
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    Solution solution;
    cout << solution.minimumTotal(triangle);

    return 0;
}
