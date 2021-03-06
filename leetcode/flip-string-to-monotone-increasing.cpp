f//
//  flip-string-to-monotone-increasing
//  https://leetcode.com/problems/flip-string-to-monotone-increasing/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        // 设子问题S[0..i]以'0'结尾时minFlips为dp[i][0]，以'1'结尾时minFlips为dp[i][1]
        //  dp[i][0] = dp[i-1][0] + (S[i]=='1')
        //  dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (S[i]=='0')
        // 递推式在i这维上只依赖i-1项，省掉i这维：
        //  dp[1] = min(dp[0], dp[1]) + (S[i]=='0')
        //  dp[0] += (S[i]=='1')  // dp[0]覆盖放后面
        int f0 = 0, f1 = 0;
        for (char c : S) {
            f1 = min(f0, f1) + (c == '0');
            f0 += (c == '1');
        }
        return min(f0, f1);
    }
};

/*
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        const int N = S.size();
        vector<int> pre(N + 1); // pre[i]表示S[..i-1]以0结尾
        for (int i = 0; i < N; i++) {
            pre[i+1] = pre[i] + (S[i] == '1');
        }
        vector<int> suf(N + 1); // suf[i]表示S[i..]以1开头
        for (int i = N - 1; i >= 0; i--) {
            suf[i] = suf[i+1] + (S[i] == '0');
        }

        int ans = INT_MAX;
        for (int i = 0; i <= N; i++) {
            ans = min(ans, pre[i] + suf[i]);
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
