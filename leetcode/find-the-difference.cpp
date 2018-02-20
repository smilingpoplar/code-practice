//
//  find-the-difference
//  https://leetcode.com/problems/find-the-difference/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (char c : s) ans ^= c;
        for (char c : t) ans ^= c;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}