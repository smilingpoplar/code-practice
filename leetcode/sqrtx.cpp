//
//  sqrtx
//  https://leetcode.com/problems/sqrtx/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1;
        // 牛顿迭代
        // 先随便猜一个数y，然后 y=(y+x/y)/2 迭代
        double y = 1;
        double lastY = -1;
        while ((int)y != (int)lastY) {
            lastY = y;
            y = (y + x / y) / 2;
        }
        return y;
    }
};
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        // 找满足r^2<=x的最大整数r，就是找满足r^2>x的最小整数r的前一个数
        int l = 1, u = x;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (mid > x / mid) { // mid*mid > x
                u = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.mySqrt(1);
    
    return 0;
}
