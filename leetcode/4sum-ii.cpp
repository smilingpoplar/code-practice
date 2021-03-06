//
//  4sum-ii
//  https://leetcode.com/problems/4sum-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> cnt; // sum=>count
        for (int a : A) {
            for (int b : B) {
                cnt[a + b]++;
            }
        }

        int ans = 0;
        for (int c : C) {
            for (int d : D) {
                int sum = c + d, toFind = -sum;
                if (cnt.count(toFind)) ans += cnt[toFind];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
