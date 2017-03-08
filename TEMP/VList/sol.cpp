#include "../../second/include/header.h"

class VList
{
private:
    list<vector<int> > mList;
    list<vector<int> >::iterator mIter;
    int mCurNum;
    int mLen;
public:
    VList(int len) : mLen(len)
    {
        vector<int> temp;
        for(int i = 0; i < len; ++i)
        {
            mList.push_back(temp);
        }
        mIter = mList.begin();
        mCurNum = 1;
    }

    void add2End(int val)
    {
        if((*mIter).size() >= mCurNum)
        {
            advance(mIter, 1);
            mCurNum <<= 1;
        }
        (*mIter).push_back(val);

        // debug
        //cout << "After Insert" << endl;
        //for(auto iter = mList.begin(); iter != mList.end(); ++iter)
        //{
        //    for(auto it = (*iter).begin(); it != (*iter).end(); ++it)
        //    {
        //        cout << *it << ", ";
        //    }
        //    cout << endl;
        //}
    }

    int valueAt(int idx)
    {
        int total = mCurNum - 1 + (*mIter).size();
        if(idx >= total) return INT_MIN;

        if(0 == idx) return (*mList.begin())[0];
        int block = ceil(log(idx) / log(2));
        int subidx = idx - pow(2, block - 1);
        auto iter = mList.begin();
        advance(iter, block);
        return (*iter)[subidx];
    }
};

int main()
{
    VList vlist(5);
    for(int i = 0; i < 10; ++i)
    {
        vlist.add2End(i);
    }
    cout << vlist.valueAt(8) << endl;
    return 0;
}
