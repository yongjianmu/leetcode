#include "../include/header.h"


/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

class cmp
{
public:
    bool operator()(int& a, int& b)
    {
        int digit_a = 0;
        int digit_b = 0;
        int x = a, y = b;
        do
        {
            ++digit_a;
            x /= 10;
        }while(0 != x);
        do
        {
            ++digit_b;
            y /= 10;
        }while(0 != y);
    
        long long tmp_a = a * pow(10, digit_b) + b;
        long long tmp_b = b * pow(10, digit_a) + a;
        cout << a << ", " << b << endl;
        cout << tmp_a << ", " << tmp_b << endl;
        return tmp_a > tmp_b ? false : true;
        //return a < b;
    }
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret = "";
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        priority_queue<int, vector<int>, cmp> s;
        for(int i = 0; i < size; ++i)
        {
            s.push(nums[i]);
        }

        while(!s.empty())
        {
            string tmp;
            stringstream ss;
            ss << s.top();
            ss >> tmp;
            s.pop();
            if("" == ret && "0" == tmp)
            {
                continue;
            }
            ret += tmp;
        }
        if("" == ret)
        {
            ret += "0";
        }
        return ret;
    }
};

int main()
{
    vector<int> input = {999999999, 999999997, 999999998};
    Solution sol;
    string result = sol.largestNumber(input);
    printResult();
    cout << result << endl;

    return 0;
}
