#include "../include/header.h"

/*
Given a non negative integer number num. For every numbers i in the range 0 = i = num calculate the number of 1's in their binary representation and return them as an array. 

Example:
 For num = 5 you should return [0,1,1,2,1,2]. 
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.push_back(0);
        if(0 == num)
        {
            return ret;
        }
        ret.push_back(1);
        if(1 == num)
        {
            return ret;
        }

        int cnt = 2;
        vector<int> cur;
        int carry = 1;
        for(int i = 2; i <= num; ++i)
        {
            //cout << i - pow(2, cnt - 1) << ", " << ret[i - pow(2, cnt - 1)] << endl;
            cur.push_back(carry + ret[i - pow(2, cnt - 1)]);
            if((i + 1) == pow(2, cnt))
            {
                ret.insert(ret.end(), cur.begin(), cur.end());
                cur.clear();
                ++cnt;
            }
        }

        if(cur.size() != 0)
        {
            ret.insert(ret.end(), cur.begin(), cur.end());
        }

        return ret;
    }
};

int main()
{
    int num = 5;
    Solution sol;
    vector<int> result = sol.countBits(num);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}

