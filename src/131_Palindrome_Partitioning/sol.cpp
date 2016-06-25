/*
 * sol.cpp
 *
 *  Created on: 2016年6月25日
 *      Author: Yongjian
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
	bool isValid(string str)
	{
		int len = str.length();
		if(1 >= len)
		{
			return true;
		}

		int start = 0;
		int end = len - 1;
		while(start <= end)
		{
			if(str[start++] != str[end--])
			{
				return false;
			}
		}
		return true;
	}

	void solve(vector<string> cur, int start, int end, string s, vector<vector<string> >& ret)
	{
		if(start >= end)
		{
			ret.push_back(cur);
			return;
		}

		for(int i = start; i < end; ++i)
		{
			string str = s.substr(start, i + 1);
			if(isValid(str))
			{
				vector<string> vec;
				vec.insert(vec.begin(), cur.begin(), cur.end());
				vec.push_back(str);
				solve(vec, i + 1, end, s, ret);
			}
		}
	}

    vector<vector<string> > partition(string s) {
    	vector<vector<string> > ret;
    	vector<string> cur;
    	solve(cur, 0, s.length(), s, ret);
    	return ret;
    }
};

int main()
{
	string s = "aab";
	Solution sol;
	vector<vector<string> > result = sol.partition(s);
	for(int i = 0; i < result.size(); ++i)
	{
		for(int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ", ";
		}
		cout << endl;
	}
	return 0;
}





