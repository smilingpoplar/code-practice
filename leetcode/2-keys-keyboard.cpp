//
//  2-keys-keyboard
//  https://leetcode.com/problems/2-keys-keyboard/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        // 一组操作是C后带若干个P，CP、CPP、...，最终n=len(CP)*len(CPP)*...
        // 这题就是把n因子分解，求所有>=2因子的和
        int ans = 0, factor = 2;
        while (n > 1) {
            while (n % factor == 0) {
                ans += factor;
                n /= factor;
            }
            factor++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
