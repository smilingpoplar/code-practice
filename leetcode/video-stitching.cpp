//
//  video-stitching
//  https://leetcode.com/problems/video-stitching/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        const int N = clips.size();
        sort(begin(clips), end(clips));
        int i = 0, ans = 0;
        int sofar = 0; // 当前已覆盖[..sofar]区间
        int frontier = 0; // 尝试扩展当前区间
        while (sofar < T) {
            while (i < N && clips[i][0] <= sofar) {
                frontier = max(frontier, clips[i][1]);
                i++;
            }
            if (frontier == sofar) return -1;
            sofar = frontier;
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
