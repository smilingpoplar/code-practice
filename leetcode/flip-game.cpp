//
//  flip-game
//  https://leetcode.com/problems/flip-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = s[i+1] = '-';
                ans.push_back(s);
                s[i] = s[i+1] = '+';
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
