#include "../include/header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        int size = strs.size();
        if(0 == size)
        {
            return ret;
        }

        int cnt = 0;
        char cur;
        while(true)
        {
            if(cnt >= strs[0].size())
            {
                break;
            }
            cur = strs[0][cnt];
            bool quit_flag = false;
            for(int i = 1; i < size; ++i)
            {
                if(cnt >= strs[i].size() || strs[i][cnt] != cur)
                {
                    quit_flag = true;
                    break;
                }
            }
            if(quit_flag)
            {
                break;
            }
            ++cnt;
        }
        ret = strs[0].substr(0, cnt);
        return ret;
    }
};

int main() {
    vector<string> input = {"aab", "aac", "aad"};
    Solution sol;
    string result = sol.longestCommonPrefix(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}