#include <stdlib.h>

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator iter;
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator hash_iter;

        for(iter = nums.begin(); iter != nums.end();)
        {
            hash_iter = mp.find(*iter);
            if(hash_iter != mp.end())
            {
                nums.erase(iter);
            }
            else
            {
                mp.insert(unordered_map<int, int>::value_type(*iter, *iter));
                ++iter;
            }
            //mp.insert(unordered_map<int, int>::value_type(1, 1));
        }

        return mp.size();
    }
};

int main()
{
	Solution sol;
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	//num.push_back(2);

	cout << sol.removeDuplicates(num) << endl;

	return 0;
}
