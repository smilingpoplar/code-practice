//
//  excel-sheet-column-number
//  https://leetcode.com/problems/excel-sheet-column-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (char c : s) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.titleToNumber("AB");
 
    return 0;
}
