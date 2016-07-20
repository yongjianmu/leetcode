#include "../include/header.h"

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int size = intervals.size();
        if(0 == size)
        {
            ret.push_back(newInterval);
            return ret;
        }

        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0;
        bool merge_end = false;
        for( ; i < size; ++i)
        {
            if(newInterval.end < intervals[i].start)
            {
                ret.push_back(newInterval);
                merge_end = true;
                break;
            }
            else if(newInterval.start < intervals[i].start && newInterval.end <= intervals[i].end)
            {
                newInterval.end = intervals[i].end;
            }
            else if(newInterval.start <= intervals[i].start && newInterval.end >= intervals[i].end)
            {
                continue;
            }
            else if(intervals[i].end < newInterval.start)
            {
                ret.push_back(intervals[i]);
            }
            else if(newInterval.start >= intervals[i].start && newInterval.end > intervals[i].end)
            {
                newInterval.start = intervals[i].start;
            }
            else if(newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end)
            {
                merge_end = true;
                break;
            }
        }

        if(!merge_end)
        {
            ret.push_back(newInterval);
        }
        else
        {
            for( ; i < size; ++i)
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main() {
    Interval l1(1, 5);
    Interval l2(6, 9);
    vector<Interval> input = {l1};
    Interval insert(2, 3);
    Solution sol;
    vector<Interval> result = sol.insert(input, insert);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i].start << ", " << result[i].end << endl;
    }

    return 0;
}