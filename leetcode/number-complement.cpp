//
//  number-complement
//  https://leetcode.com/problems/number-complement/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // 先找哪些是有效位
        int mask = ~0;
        while (mask & num) mask <<= 1;
        return ~mask ^ num;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
