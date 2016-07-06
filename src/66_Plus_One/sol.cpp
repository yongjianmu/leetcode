#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		vector<int>::reverse_iterator riter;
		for(riter = digits.rbegin(); riter != digits.rend(); ++riter)
		{
			if(0 == carry)
			{
				break;
			}

			if(10 <= *riter + carry)
			{
				*riter = (*riter + carry) % 10;
				carry = 1;
			}
			else
			{
				*riter += carry;
				carry = 0;
			}
		}

		if(1 == carry)
		{
			vector<int> ret;
			ret.push_back(carry);
			ret.insert(ret.begin() + 1, digits.begin(), digits.end());
			return ret;
		}

		return digits;
    }
};

int main()
{
	vector<int> input;
	input.push_back(0);
	Solution sol;
	vector<int> output = sol.plusOne(input);
	for(int i = 0; i < output.size(); ++i)
	{
		cout << output[i] << ", ";
	}
	cout << endl;

	return 0;
}
