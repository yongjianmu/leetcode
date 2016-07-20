#include "../include/header.h"

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b)
{
    if(a.start == b.start)
    {
        return a.end < b.end;
    }
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int size = intervals.size();
        if(1 >= size)
        {
            return intervals;
        }

        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur = intervals[0];
        for(int i = 1; i < size; ++i)
        {
            if(intervals[i].start == cur.start && intervals[i].end == cur.end)
            {
                continue;
            }
            if(intervals[i].start <= cur.end && intervals[i].end >= cur.end)
            {
                cur.end = intervals[i].end;
            }
            else if(intervals[i].start > cur.end)
            {
                ret.push_back(cur);
                cur = intervals[i];
            }
        }
        ret.push_back(cur);
        return ret;
    }
};

int main() {
    Interval i1(1, 4);
    Interval i2(2, 3);
    Interval i3(8, 10);
    Interval i4(15, 18);
    vector<Interval> input = {i1, i2};
    Solution sol;
    vector<Interval> result = sol.merge(input);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i].start << ", " << result[i].end << endl;
    }

    return 0;
}