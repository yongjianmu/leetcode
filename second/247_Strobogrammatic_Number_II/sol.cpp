#include "../include/header.h"

class Solution {
public:
    vector<string> mRet;
    vector<char> mMid;
    vector<pair<char, char> > mSide;
    
    void solve(int start, int end, vector<string>& s)
    {
        if(start > end)
        {
            for(auto it = s.begin(); it != s.end(); ++it)
            {
               if((*it).size() > 1 && (*it)[0] == '0')
               {
                   continue;
               }
               mRet.push_back(*it);
            }
            return;
        }
        
        if(start == end)
        {
            for(auto iter = mMid.begin(); iter != mMid.end(); ++iter)
            {
                for(auto it = s.begin(); it != s.end(); ++it)
                {
                    (*it)[start] = *iter;
                    if((*it).size() > 1 && (*it)[0] == '0')
                    {
                        continue;
                    }
                    mRet.push_back(*it);
                }
            }
            return;
        }
        
        vector<string> t;
        for(auto iter = mSide.begin(); iter != mSide.end(); ++iter)
        {
            for(auto it = s.begin(); it != s.end(); ++it)
            {
                (*it)[start] = iter->first, (*it)[end] = iter->second;
                t.push_back(*it);
            }
        }
        
        solve(start + 1, end - 1, t);
    }
    
    vector<string> findStrobogrammatic(int n) {
        if(0 == n)
        {
            return mRet;
        }
        
        mMid.push_back('0');
        mMid.push_back('1');
        mMid.push_back('8');
        
        mSide.push_back(make_pair('0', '0'));
        mSide.push_back(make_pair('1', '1'));
        mSide.push_back(make_pair('8', '8'));
        mSide.push_back(make_pair('6', '9'));
        mSide.push_back(make_pair('9', '6'));
        
        int start = 0, end = n - 1;
        vector<string> vec;
        string str(n, '1');
        vec.push_back(str);
        
        solve(start, end, vec);
        return mRet;
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.findStrobogrammatic(3);
    printResult();
    printVector1D(result, true);
    return 0;
}
