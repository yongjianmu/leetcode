#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int a_len = a.length();
		int b_len = b.length();
		string ret(max(a_len, b_len), '0');
		int a_count = a_len - 1, b_count = b_len - 1;
		int carry = 0;
		while(0 <= a_count || 0 <= b_count)
		{
			char a_tmp = '0',  b_tmp = '0';
			if(0 <= a_count)
			{
				a_tmp = a[a_count--];
			}

			if(0 <= b_count)
			{
				b_tmp = b[b_count--];
			}
			
			ret[max(a_count + 1, b_count + 1)] = '0' + (((a_tmp - '0') + (b_tmp - '0') + carry) % 2);
			if((a_tmp - '0') + (b_tmp - '0') + carry > 1)
			{
				carry = 1;
			}
			else
			{
				carry = 0;
			}

		}

		if(1 == carry)
		{
			ret = "1" + ret;
		}

		return ret;

    }
};

int main()
{
	string a = "1010";
	string b = "1011";
	Solution sol;
	cout << sol.addBinary(a, b) << endl;
	return 0;
}
