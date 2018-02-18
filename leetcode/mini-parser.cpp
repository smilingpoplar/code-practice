//
//  mini-parser
//  https://leetcode.com/problems/mini-parser/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        auto isnumber = [](char c) { return isdigit(c) || c == '-'; };
        stack<NestedInteger> stk;
        stk.push({}); // dummy
        for (int i = 0; i < s.size();) {
            if (isnumber(s[i])) {
                int start = i;
                while (i < s.size() && isnumber(s[i])) i++;
                int num = stoi(s.substr(start, i - start));
                stk.top().add({num});
            } else {
                if (s[i] == '[') {
                    stk.push({});
                } else if (s[i] == ']') {
                    auto top = stk.top();
                    stk.pop();
                    stk.top().add(top);
                }
                i++;
            }
        }
        return stk.top().getList()[0];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
