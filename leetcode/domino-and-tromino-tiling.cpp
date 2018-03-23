//
//  domino-and-tromino-tiling
//  https://leetcode.com/problems/domino-and-tromino-tiling/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        // 设d[i]表示铺满2*i格子的方式数，t[i]表示缺一角铺满2*i-1格子的方式数
        // d[i] = d[i-1] /* 一竖 */ + d[i-2] /* 两横 */ + 2* t[i-1] /*两个不同朝向的L型*/
        // t[i] = t[i-1] /* 一横 */ + d[i-2] /* 一个L型 */
        // 初始 d[0]=d[1]=1, t[0]=t[1]=0；d[0]=1是由t[2]=1逆推得到
        const int MOD = 1e9 + 7;
        vector<int> d(N + 1, 0);
        vector<int> t(N + 1, 0);
        d[0] = d[1] = 1;
        for (int i = 2; i <= N; i++) {
            d[i] = (d[i-1] + d[i-2] + 2l * t[i-1]) % MOD;
            t[i] = (t[i-1] + d[i-2]) % MOD;
        }
        return d[N];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}