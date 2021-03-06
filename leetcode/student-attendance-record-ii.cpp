//
//  student-attendance-record-ii
//  https://leetcode.com/problems/student-attendance-record-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        // 各个条件作dp的一个维度，设dp[i][a][l]表示s[0..i)、*最多*有a个A、末尾*最多*有l个连续L的有效记录数
        // 原问题求dp[n][1][2]，初始dp[0][][]=1（因为“最多”，所以空串都有效）
        // dp[i][a][l] = dp[i-1][a-1][2] //..A，l重置为最大值2
        //               + dp[i-1][a][l-1] //..L
        //               + dp[i-1][a][2] //..P
        // 递推式在i维上只依赖于i-1项，省掉i这维，i仍从左往右遍历
        // 降维使用临时变量：ndp[a][l] = dp[a-1][2] + dp[a][l-1] + dp[a][2]
        const int MOD = 1e9 + 7;
        array<array<int, 3>, 2> dp = {{
            {1,1,1}, {1,1,1},
        }}; // i==0
        for (int i = 1; i <= n; i++) {
            array<array<int, 3>, 2> ndp;
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    long val = dp[a][2]; // ..P
                    if (a > 0) val += dp[a-1][2]; // ..A
                    if (l > 0) val += dp[a][l-1]; // ..L
                    ndp[a][l] = val % MOD;
                }
            }
            swap(dp, ndp);
        }
        return dp[1][2];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
