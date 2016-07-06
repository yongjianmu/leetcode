#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int ret = 0;
        int size = height.size();
        if(0 >= size)
        {
            return ret;
        }

        int L = 0, R = size - 1;
        while(L < R)
        {
            ret = max(ret, (R - L) * min(height[R], height[L]));
            if(height[L] > height[R])
            {
                --R;
            }
            else
            {
                ++L;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> height;
    for(int i = 0; i < 10; ++i)
    {
        height.push_back(i);
    }

    Solution sol;
    cout << sol.maxArea(height) << endl;

    return 0;
}
