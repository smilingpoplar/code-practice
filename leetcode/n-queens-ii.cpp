//
//  n-queens-ii
//  https://leetcode.com/problems/n-queens-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        // 按行放置，place[i]=j 表示在第i行的第j列放置皇后
        vector<int> place(n, -1);
        // 放置皇后时的判断条件
        vector<bool> cols(n, false), diag(2 * n - 1, false), antidiag(2 * n - 1, false);

        int ans = 0;
        search(0, place, cols, diag, antidiag, ans);
        return ans;
    }

    void search(int r, vector<int> &place, vector<bool> &cols, 
                vector<bool> &diag, vector<bool> &antidiag, int &ans) {
        const int N = place.size();
        if (r == N) {
            ans++;
            return;
        }
        
        for (int c = 0; c < N; c++) {
            if (cols[c] || diag[r + c] || antidiag[r - c + N - 1]) continue;
            place[r] = c;
            cols[c] = diag[r + c] = antidiag[r - c + N - 1] = true;
            search(r + 1, place, cols, diag, antidiag, ans);
            place[r] = -1;
            cols[c] = diag[r + c] = antidiag[r - c + N - 1] = false;
        }
    }
};

int main(int argc, const char * argv[]) {
    int n = 4;
    Solution solution;
    int ans = solution.totalNQueens(n);
    cout << ans;
    
    return 0;
}
