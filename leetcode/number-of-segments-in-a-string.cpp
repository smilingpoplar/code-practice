//
//  number-of-segments-in-a-string
//  https://leetcode.com/problems/number-of-segments-in-a-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == s.size() - 1 || s[i + 1] == ' ')) { // 单词末尾
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
