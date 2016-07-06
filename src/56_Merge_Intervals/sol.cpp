#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
   Given [1,3],[2,6],[8,10],[15,18],
   return [1,6],[8,10],[15,18].
   */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> ret;
            int size = intervals.size();
            if(0 == size)
            {
                return ret;
            }

            // Merge items which has the same first value
            unordered_map<int, int> dict;
            vector<int> key_list;
            for(int i = 0; i < size; ++i)
            {
                if(dict.find(intervals[i].start) == dict.end())
                {
                    dict[intervals[i].start] = intervals[i].end;
                    key_list.push_back(intervals[i].start);
                }
                else
                {
                    if(dict[intervals[i].start] < intervals[i].end)
                    {
                        dict[intervals[i].start] = intervals[i].end;
                    }
                }
            }

            sort(key_list.begin(), key_list.end());

            Interval curr(key_list[0], dict[key_list[0]]);
            for(int i = 1; i < key_list.size(); ++i)
            {
                if(curr.end >= key_list[i])
                {
                    if(curr.end < dict[key_list[i]])
                    {
                        curr.end = dict[key_list[i]];
                    }
                }
                else
                {
                    ret.push_back(curr);
                    curr.start = key_list[i];
                    curr.end = dict[key_list[i]];
                }
            }
            ret.push_back(curr);

            return ret;
        }
};

int main()
{
    Interval i1(1, 4);
    Interval i2(1, 5);
    Interval i3(8, 10);
    Interval i4(15, 18);

    vector<Interval> input;
    input.push_back(i1);
    input.push_back(i2);
    //input.push_back(i3);
    //input.push_back(i4);

    Solution sol;
    vector<Interval> result = sol.merge(input);
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i].start << ", " << result[i].end << endl;
    }

    return 0;
}
