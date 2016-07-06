#include "../include/header.h"

/*
add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
*/

class MedianFinder {
public:
    int mTotalNum;
    multiset<int> mSet;

    MedianFinder()
    {
        mTotalNum = 0;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        ++mTotalNum;
        mSet.insert(num);
    }

    // Returns the median of current data stream
    double findMedian() {
        double ret = 0.0;
        if (0 == mTotalNum % 2)
        {
            int mid_right = mTotalNum >> 1;
            int cnt = 0;
            int left = 0, right = 0;
            for(auto iter = mSet.begin(); iter != mSet.end(); ++iter)
            {
                if(cnt == mid_right - 1)
                {
                    left = *iter;
                }

                if (cnt == mid_right)
                {
                    right = *iter;
                    break;
                }
                ++cnt;
            }

            ret = static_cast<double> (left + right) / 2.0;
        }
        else
        {
            int mid = mTotalNum >> 1;
            int cnt = 0;
            for (auto iter = mSet.begin(); iter != mSet.end(); ++iter)
            {
                if (cnt == mid)
                {
                    ret = *iter * 1.0;
                    break;
                }
                ++cnt;
            }
        }
        return ret;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main()
{
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(5);
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    return 0;
}