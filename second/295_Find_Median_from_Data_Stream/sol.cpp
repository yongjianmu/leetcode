#include "../include/header.h"


class MedianFinder {
public:
    vector<int> mVec;
    int mNum;

    MedianFinder()
    {
        mNum = 0;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if(0 == mNum)
        {
            mVec.push_back(num);
            ++mNum;
            return;
        }

        int start = 0, end = mNum - 1;
        auto iter = mVec.begin();
        while(start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if(mVec[mid] == num)
            {
                advance(iter, mid + 1);
                mVec.insert(iter, num);
                break;
            }
            else if(mVec[mid] < num)
            {
                if(mid == mNum - 1 || mVec[mid + 1] >= num)
                {
                    advance(iter, mid + 1);
                    mVec.insert(iter, num);
                    break;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if(mid == 0)
                {
                    mVec.insert(iter, num);
                    break;
                }
                else if(mVec[mid - 1] <= num)
                {
                    advance(iter, mid);
                    mVec.insert(iter, num);
                    break;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        ++mNum;
        printVector1D(mVec, false);
    }

    // Returns the median of current data stream
    double findMedian() {
        if(0 == mNum)
        {
            return 0.0;
        }

        if(0 == mNum % 2)
        {
            int pos = (mNum - 1) >> 1;
            return (mVec[pos] + mVec[pos + 1]) * 1.0 / 2;
        }
        else
        {
            return mVec[mNum >> 1] * 1.0;
        }
    }
};


int main()
{
    // Your MedianFinder object will be instantiated and called as such:
    MedianFinder mf;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(10);
    cout << mf.findMedian() << endl;
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(5);
    cout << mf.findMedian() << endl;
    mf.addNum(0);
    cout << mf.findMedian() << endl;

    return 0;
}
