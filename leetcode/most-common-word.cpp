//
//  most-common-word
//  https://leetcode.com/problems/most-common-word/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(banned.begin(), banned.end());
        for (char &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        
        istringstream iss(paragraph);
        string word;
        unordered_map<string, int> cnt; // word=>count
        int maxCnt = INT_MIN;
        string ans;
        while (iss >> word) {
            if (st.count(word)) continue;
            if (++cnt[word] > maxCnt) {
                maxCnt = cnt[word];
                ans = word;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
