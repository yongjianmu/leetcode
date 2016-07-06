#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter;
        int old = 0;
        int ret = 0;
        int cnt = 0;
        bool flag = false;
        for(iter = nums.begin(); iter != nums.end(); ++iter)
        {
            if(*iter <= 0)
            {
                ++cnt;
                continue;
            }
            else
            {
                if(!flag && *iter > 1)
                {
                    cout << "$$$" << endl;
                    return 1;
                }
                if(old > 0)
                {

                    if(*iter - old > 1)
                    {
                        ret = old + 1;
                        break;
                    }
                }
                flag = true;
            }
            old = *iter;
            ++cnt;
        }

        if(cnt < nums.size())
        {
            cout << "###" << endl;
            return ret;
        }
        else
        {
            if(old > 0)
            {
                cout << "***" << old + 1 << endl;
                return old + 1;
            }
            else
            {
                cout << "***" << endl;
                return 1;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v.push_back(2);
    v.push_back(1);

    cout << sol.firstMissingPositive(v) << endl;
    cout << "Output sorted nums" << endl;
    std::vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
