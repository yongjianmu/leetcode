#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 0;
        int size = ratings.size();
        if(0 == size)
        {
            return ret;
        }

        sort(ratings.begin(), ratings.end());
        int curr = 1;
        for(int i = 0; i < size; ++i)
        {
            if(0 == i)
            {
                ret += curr;
            }
            else
            {
                if(ratings[i] == ratings[i - 1])
                {
                    ret += curr;
                }
                else
                {
                    ++curr;
                    ret += curr;
                }
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> ratings = {5, 1, 2, 3};
    Solution sol;
    cout << sol.candy(ratings) << endl;
    return 0;
}
