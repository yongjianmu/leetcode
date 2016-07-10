#include "../include/header.h"

/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2]. 
 */
 
class Solution {
public:
	typedef pair<int, int> MyPair;
	
	struct MyTestCompare
	{
		bool operator()(const MyPair& firstPair, const MyPair& secondPair) const
		{
			return firstPair.second >= secondPair.second;
		}
	};
	
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret(k, 0);
		unordered_map<int, int> mp;
		for(int i = 0; i < nums.size(); ++i)
		{
			++mp[nums[i]];
		}
		
		set<MyPair, MyTestCompare> s;
		for(auto iter = mp.begin(); iter != mp.end(); ++iter)
		{
			s.insert(*iter);
		}
		
		int cnt = 0;
		for(auto iter = s.begin(); iter != s.end(); ++iter)
		{
			if(cnt == k)
			{
				break;
			}
			cout << iter->first << ", " << iter->second << endl;
			ret[cnt] = iter->first;
			++cnt;
		}
		return ret;
    }
};

int main()
{
	vector<int> input = {1, 2};
	int k = 2;
	Solution sol;
	vector<int> result = sol.topKFrequent(input, k);
	cout << "#### Result ####" << endl;
	for(int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ", ";
	}
	cout << endl;
	
	return 0;
}
