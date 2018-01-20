//
//  best-time-to-buy-and-sell-stock-iii
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = (int)prices.size();
        if (N < 2) return 0;
        
        // 设dp[i][j][s]表示第i天、剩余交易数j、手上s股股票时的最大利润，s=0或1
        // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i] /*卖股票*/)
        // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i] /*买股票，新交易*/)
        // 初始dp[-1][j][0]=0，dp[-1][j][1]=INT_MIN
        // dp[i][][]只依赖dp[i-1][][]，降一维
        const int k = 2;
        vector<vector<int>> dp(k + 1, vector<int>({ 0, INT_MIN }));
        for (int price : prices) {
            for (int j = k; j >= 1; --j) { // 倒序，这样等号右边的dp[j-1][]来自旧状态[i-1]
                dp[j][0] = max(dp[j][0], dp[j][1] + price);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - price);
            }
        }
        return dp[k][0];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,3,2,1,2};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
