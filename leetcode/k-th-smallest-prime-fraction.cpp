//
//  k-th-smallest-prime-fraction
//  https://leetcode.com/problems/k-th-smallest-prime-fraction/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // 就是在行列有序的矩阵中找第K小的数
        // 1/5  2/5  3/5
        // 1/3  2/3
        // 1/2
        
        // 用优先队列法，队列里存行列坐标，第一列先进队列
        const int N = A.size();
        auto cmp = [&A](vector<int> &a, vector<int> &b) { // 最小堆
            return A[a[0]] * A[b[1]] > A[b[0]] * A[a[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 1; i < N; i++) pq.push({0, i});
        int k = 0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            if (++k == K) return {A[top[0]], A[top[1]]};
            if (top[0] + 1 < top[1]) {
                pq.push({top[0] + 1, top[1]});
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}