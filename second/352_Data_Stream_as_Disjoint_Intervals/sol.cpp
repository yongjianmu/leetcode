#include "../include/header.h"
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(0 == mInterval.size())
        {
            mInterval.push_back(Interval(val, val));
            return;
        }

        int cur_start = 0, cur_end = 0;
        int left = 0, right = mInterval.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(mInterval[mid].end < val) left = mid + 1;
            else right = mid - 1;
        }
        cur_start = right;

        left = 0; right = mInterval.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(mInterval[mid].start < val) left = mid + 1;
            else right = mid - 1;
        }
        cur_end = left;

        cout << cur_start << "###" << cur_end << endl;
        auto iter = mInterval.begin();
        advance(iter, cur_start);
        int val_s = val, val_e = val;
        bool del_flag = false;

        if(mInterval[cur_start].end == val_s - 1)
        {
            val_s = mInterval[cur_start].start;
            mInterval.erase(iter);
            del_flag = true;
        }
        else
        {
            ++iter;
        }

        if(del_flag) --cur_end;
        if(mInterval[cur_end].start == val_e + 1)
        {
            val_e = mInterval[cur_end].end;
            mInterval.erase(iter);
        }

        mInterval.insert(iter, Interval(val_s, val_e));
    }
    
    vector<Interval> getIntervals() {
        return mInterval;
    }

private:
    vector<Interval> mInterval;
};

int main()
{
    SummaryRanges obj;
    //vector<int> nums = {1,2,4,6,7,5};
    vector<int> nums = {1,3,7,2,6,9,4,10,5};
    for(auto num : nums)
    {
        obj.addNum(num);
        vector<Interval> param_2 = obj.getIntervals();
        printResult();
        for(Interval interval : param_2)
        {
            cout << "[" << interval.start << "," << interval.end << "]" << endl;
        }

        cout << endl;
    }
    return 0;
}
