//
//  find-k-closest-elements
//  https://leetcode.com/problems/find-k-closest-elements/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); // arr[j]是第一个>=x的数
        int i = j - 1;
        while (k--) {
            // i >= 0 && j < arr.size() && x - arr[i] > arr[j] - x  => j++
            // i >= 0 && j < arr.size() && x - arr[i] <= arr[j] - x  => i--
            // i < 0  => j++
            // j >= arr.size()  => i--
            if (i < 0 || (j < arr.size() && x - arr[i] > arr[j] - x)) {
                j++;
            } else {
                i--;
            }
        }
        // (i,j)是前开后开区间
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
