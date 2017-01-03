#include "../include/header.h"

class MedianFinder {
public:
    multiset<int> mWords;

    // Adds a number into the data structure.
    void addNum(int num) {
        mWords.insert(num);
    }

    // Returns the median of current data stream
    double findMedian() {
        double ret = 0.0;
        int mid = mWords.size() >> 1;
        if(mWords.size() % 2 == 0)
        {
            auto iterl = mWords.begin();
            advance(iterl, mid - 1);
            auto iterr = mWords.begin();
            advance(iterr, mid);
            cout << *iterl << ", " << *iterr << endl;
            ret = (*iterl + *iterr) * 1.0 / 2;
        }
        else
        {
            auto iter = mWords.begin();
            advance(iter, mid);
            ret = *iter;
        }
        return ret;
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
