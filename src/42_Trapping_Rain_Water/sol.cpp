#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int old = 0, L = 0, R = height.size() - 1;
		int ans = 0;
		while (L < R)
		{
			if (height[L] < height[R])
			{
				if (old < height[L])
					old = height[L];
				else
					ans+=old - height[L];
				L++;
			}
			else
			{
				if (old < height[R])
					old = height[R];
				else
					ans += old - height[R];
				R--;

			}
		}
		return ans;
    }
};


int main()
{
    return 0;
}
