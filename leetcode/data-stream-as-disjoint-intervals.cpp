//
//  data-stream-as-disjoint-intervals
//  https://leetcode.com/problems/data-stream-as-disjoint-intervals/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        // 首个与[val,val]重叠区间toFind.end>=val-1
        auto it = st.lower_bound({INT_MIN, val - 1}); 
        Interval adding({ val, val });
        while (it != st.end() && isOverlap(*it, adding)) {
            adding.start = min(adding.start, it->start);
            adding.end = max(adding.end, it->end);
            it = st.erase(it);
        }
        st.insert(adding);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(st.begin(), st.end());
    }
private:
    struct Cmp {
        bool operator()(const Interval &a, const Interval &b) const { return a.end < b.end; }
    };
    set<Interval, Cmp> st;

    bool isOverlap(const Interval &a, const Interval &b) {
        return (a.start <= b.end + 1) && (b.start <= a.end + 1);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
