#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int sign = x >> 31;

        while(x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }

		if(result > INT_MAX || result < INT_MIN)
		{
			cout << "Overflow" << endl;
			return 0;
		}
        //if(sign != result >> 31)
        //{
        //    cout << "Overflow..." << endl;
        //    return 0;
        //}

        return result;
    }
};

int main()
{
	int x;
	cin >> x;

	Solution sol;
	cout << sol.reverse(x) << endl;

	return 0;
}
