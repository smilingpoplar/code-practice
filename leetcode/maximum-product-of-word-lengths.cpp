//
//  maximum-product-of-word-lengths
//  https://leetcode.com/problems/maximum-product-of-word-lengths/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size(), 0); // 单词中的字母出现用1位表示
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; j++) {
                if (!(masks[i] & masks[j])) {
                    int len = words[i].size() * words[j].size();
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}