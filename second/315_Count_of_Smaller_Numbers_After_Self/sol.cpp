#include "../include/header.h"

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

class FenwickTree {
	vector<int> sum_array;
	int n;
	inline int lowbit(int x) {
		return x & -x;
	}

public:
	FenwickTree(int n) :n(n), sum_array(n + 1, 0) {}

	void add(int x, int val) {
		while (x <= n) {
			sum_array[x] += val;
			x += lowbit(x);
		}
	}
	
	int sum(int x) {
		int res = 0;
		while (x > 0) {
			res += sum_array[x];
			x -= lowbit(x);
		}
		return res;
	}
};

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> temp_num = nums;
		sort(temp_num.begin(), temp_num.end());
		unordered_map<int,int> dic;
		for (int i = 0; i < temp_num.size(); i++) 
			dic[temp_num[i]] = i + 1;

		FenwickTree tree(nums.size());
		vector<int> ans(nums.size(),0);
		for (int i = nums.size() - 1; i >= 0; i--) {
			ans[i] = tree.sum(dic[nums[i]] - 1);
			tree.add(dic[nums[i]],1);
		}
		return ans;
	}
};

int main()
{
    vector<int> input = {5, 2, 6, 1};
    Solution sol;
    vector<int> result = sol.countSmaller(input);
    printResult();
    printVector1D(result);

    return 0;
}
