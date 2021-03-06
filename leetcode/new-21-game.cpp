//
//  new-21-game
//  https://leetcode.com/problems/new-21-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        // 题目：<K时不断得[1..W]分，求最后得分在[K..N]间的概率
        if (K == 0 || N - K + 1 >= W) return 1;
        // 设dp[i]表示得分为i的概率，则dp[i]=sum{dp[i-W..i-1]}/W
        // 由于得分>=K就不再得分，dp[K..i-1]=0，dp[i]=sum{dp[i-W..min(K-1,i-1)]}/W
        // 维护一个长<=W的窗口，设Wsum=sum{dp[i-W..min(K-1,i-1)]}
        vector<double> dp(N + 1, 0);
        dp[0] = 1;
        double Wsum = dp[0], ans = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = Wsum / W;
            // 更新Wsum
            if (i < K) Wsum += dp[i]; // min(K-1,i-1)=i-1，扩展窗口右边界
            else ans += dp[i]; // min(K-1,i-1)=K-1，不用扩展窗口右边界；i>=K，正好可以统计[K..N]间的概率
            if (i-W >= 0) Wsum -= dp[i-W]; // 收缩窗口左边界
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
