//
//  spiral-matrix-iii
//  https://leetcode.com/problems/spiral-matrix-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // 往右下左上方向不断走1,1,2,2,3,3,4,4,5,5,...步
        // 从索引i（0-based）生成步数的通式是 i/2+1
        const vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        
        int r = r0, c = c0;
        for (int i = 0; ans.size() < R * C; i++) {
            auto &dir = dirs[i%4]; // 方向
            for (int k = 0; k < i / 2 + 1; k++) { // 走i/2+1步
                r += dir[0], c += dir[1];
                if (0 <= r && r < R && 0 <= c && c < C) ans.push_back({r, c});
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
