//
//  kth-smallest-number-in-multiplication-table
//  https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 设第k个数为x，x在范围[1..m*n]
        // 设二分搜索条件enough(x)表示"<=x的个数"count>=k
        int l = 0, u = m * n + 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, m, n, k)) {
                u = mid;
            } else {
                l = mid;
            }
        }
        return u;
    }
    
    bool enough(int x, int m, int n, int k) {
        // 乘法表一行行看有多少数<=乘积x
        int count = 0;
        for (int r = 1; r <= m; r++) {
            count += min(x / r, n);
        }
        return count >= k;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
