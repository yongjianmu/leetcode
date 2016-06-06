#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ret;
        int size = strs.size();
        if(0 == size)
        {
            return ret;
        }

        unordered_map<string, int> dict;
        int count = 0;

        for(int i = 0; i < size; ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            unordered_map<string, int>::iterator iter = dict.find(tmp);
            if(iter == dict.end())
            {
                dict[tmp] = count++;
                vector<string> new_str;
                new_str.push_back(strs[i]);
                ret.push_back(new_str);
                
            }
            else
            {
                ret[iter->second].push_back(strs[i]);
            }
        }

        return ret;
    }
};

int main()
{
    vector<string> input;
    input.push_back("eat");
    input.push_back("tea");
    input.push_back("nat");
    input.push_back("tan");
    input.push_back("bat");

    Solution sol;
    vector<vector<string> > result = sol.groupAnagrams(input);

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
