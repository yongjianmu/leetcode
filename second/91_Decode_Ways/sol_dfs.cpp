#include "../include/header.h"

void dfs(int pos, int len, string nums, string cur, vector<string>& ret, bool& flag)
{
    if(flag)
    {
        return;
    }

    if(pos >= len)
    {
        ret.push_back(cur);
        return;
    }

    if(nums[pos] == '0')
    {
        flag = true;
        return;
    }

    string temp = cur;
    if(pos == len - 1)
    {
        temp.push_back('A' + (nums[pos] - '0' - 1));
        dfs(pos + 1, len, nums, temp, ret, flag);
    }
    else
    {
        if(nums[pos + 1] == '0')
        {
            if(nums[pos] > '2')
            {
                flag = true;
                return;
            }
            int diff = stoi(nums.substr(pos, 2));
            cout << diff << endl;
            temp.push_back('A' + diff - 1);
            dfs(pos + 2, len, nums, temp, ret, flag);
        }
        else
        {
            temp.push_back('A' + (nums[pos] - '0' - 1));
            dfs(pos + 1, len, nums, temp, ret, flag);
            if((pos == len - 2 || nums[pos + 2] != '0') && (nums[pos] == '1' ||(nums[pos] == '2' && nums[pos + 1] <= '6')))
            {
                temp.pop_back();
                int diff = stoi(nums.substr(pos, 2));
                temp.push_back('A' + diff - 1);
                dfs(pos + 2, len, nums, temp, ret, flag);
            }
        }
    }

}

vector<string> decodeWays(string nums)
{
    vector<string> ret;
    string cur = "";
    int len = nums.length();
    bool flag = false;
    dfs(0, len, nums, cur, ret, flag);
    return flag ? vector<string>() : ret;
}

int main()
{
    string input = "12106";
    vector<string> result = decodeWays(input);
    printResult();
    printVector1D(result, true);
    return 0;
}
