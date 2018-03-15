//
//  strobogrammatic-number
//  https://leetcode.com/problems/strobogrammatic-number/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9', '6'}};
        int i = 0, j = (int)num.size() - 1;
        while (i <= j) {
            if (mp.find(num[i]) == mp.end()) return false;
            if (mp[num[i]] != num[j]) return false;
            i++, j--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
