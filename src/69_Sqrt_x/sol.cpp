#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if(0 == x)
		{
			return 0;
		}

		long long L = 1;
		long long R = x >> 1;
		long long ret = 0;
		while(L < R)
		{
			long long mid = (L + R) >> 1;
			ret = mid * mid;
			if(ret == x)
			{
				return mid;
			}
			else if(ret > x)
			{
				R = mid - 1;
			}
			else
			{
				L = mid + 1;
			}
		}

		ret = L * L;
		return ret > x ? L - 1 : L;
    }
};

int main()
{
	Solution sol;
	cout << sol.mySqrt(25) << endl;
	return 0;
}
