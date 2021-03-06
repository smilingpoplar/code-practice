//
//  excel-sheet-column-title
//  https://leetcode.com/problems/excel-sheet-column-title/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            char c = (n - 1) % 26 + 'A';
            s = c + s;
            n = (n - 1) / 26;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.convertToTitle(28);
 
    return 0;
}
