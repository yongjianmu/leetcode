class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> ret;
		map<int, int> mp;
		map<int, int>::iterator iter;
		int length = nums.size();
		
		for(int i = 0; i < length; ++i)
		{
			mp[nums[i]] = i;
		}


		for(int i = 0; i < length; ++i)
		{
			iter = mp.find(target - nums[i]);
			if((iter != mp.end()) && (iter->second != i))
			{
				ret.push_back(min(i, iter->second));
				ret.push_back(max(i, iter->second));
				break;
			}
		}
		return ret;
    }
};

