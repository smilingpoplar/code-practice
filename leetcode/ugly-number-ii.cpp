//
//  ugly-number-ii
//  https://leetcode.com/problems/ugly-number-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // 每个因子x对应一个要相乘的已知丑数seq[ix]，以生成下个丑数 min{ seq[ix]*x }
        // 当生成了下个丑数后，所有参与生成的因子的索引ix++
        vector<int> seq;
        seq.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            int next = min({ seq[i2] * 2, seq[i3] * 3, seq[i5] * 5 });
            seq.push_back(next);
            if (next == seq[i2] * 2) i2++;
            if (next == seq[i3] * 3) i3++;
            if (next == seq[i5] * 5) i5++;
        }
        return seq.back();
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.nthUglyNumber(5);
    
    return 0;
}
