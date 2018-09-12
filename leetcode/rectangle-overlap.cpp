//
//  rectangle-overlap
//  https://leetcode.com/problems/rectangle-overlap/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2]
            && rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}