//
//  factorial-trailing-zeroes
//  https://leetcode.com/problems/factorial-trailing-zeroes/
//
//  Created by smilingpoplar on 15/6/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        // n!末尾0的个数 等于 [1,n]中因子5的个数
        // 即 n/5 + n/25 + n/125 + ...
        int count = 0;
        while (n /= 5) {
            count += n;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.trailingZeroes(25);
    
    return 0;
}