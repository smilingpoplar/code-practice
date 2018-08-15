//
//  coin-change
//  https://leetcode.com/problems/coin-change/
//
//  Created by smilingpoplar on 17/10/12.
//  Copyright (c) 2017年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题
        // 背包容量是amount，物品体积是硬币面值，物品价值是硬币数1，要使总价值最小
        const int theMax = amount + 1;
        vector<int> dp(amount + 1, theMax);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) { // 正序遍历
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return (dp[amount] != theMax) ? dp[amount] : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
