//
//  network-delay-time
//  https://leetcode.com/problems/network-delay-time/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : times) {
            adj[e[0]][e[1]] = e[2];
        }
        vector<int> dists(N + 1, INT_MAX);
        dists[K] = 0;
        
        // vector<int> visited(N + 1, false);
        auto cmp = [](vector<int> &a, vector<int> &b) { // {node, dist}
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({K, dists[K]});
        while (!pq.empty()) {
            auto info = pq.top(); pq.pop();
            int u = info[0], dist = info[1];
            // if (visited[u]) continue;
            // visited[u] = true;
            for (auto &e : adj[u]) { // 遍历u的所有邻接点
                int v = e.first, cost = e.second;
                int newdist = dist + cost;
                if (newdist < dists[v]) {
                    dists[v] = newdist;
                    pq.push({v, newdist}); // pq中将可能有多个v值，但后续v值对结果没影响。可用visited[]来排除。
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i < dists.size(); i++) {
            ans = max(ans, dists[i]);
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
