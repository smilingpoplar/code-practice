//
//  asteroid-collision
//  https://leetcode.com/problems/asteroid-collision/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int i = 0; i < asteroids.size(); i++) {
            if (stk.empty() || stk.back() < 0 || asteroids[i] > 0) {
                stk.push_back(asteroids[i]);
            } else if (stk.back() == -asteroids[i]) {
                stk.pop_back();
            } else if (stk.back() < -asteroids[i]) {
                stk.pop_back();
                i--; // 与待会儿的i++抵消，继续看asteroids[i]
            }
        }
        return stk;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
