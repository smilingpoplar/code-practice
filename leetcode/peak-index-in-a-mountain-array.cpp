//
//  peak-index-in-a-mountain-array
//  https://leetcode.com/problems/peak-index-in-a-mountain-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, u = (int)A.size() - 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
                return mid;
            } else if (A[mid-1] >= A[mid]) {
                u = mid;
            } else {
                l = mid;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
