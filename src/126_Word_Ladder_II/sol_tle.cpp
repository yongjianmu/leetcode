#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <unordered_set>

using namespace std;


/*
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/


class Solution {
public:
    bool isValid(string src, string dst)
    {
        int cnt = 0;
        string::iterator iter_src = src.begin();
        string::iterator iter_dst = dst.begin();

        while(iter_src != src.end() && iter_dst != dst.end())
        {
            if(*iter_src++ != *iter_dst++)
            {
                ++cnt;
            }
        }

        if(1 == cnt && iter_src == src.end() && iter_dst == dst.end())
        {
            return true;
        }

        return false;
    }

    void solve(vector<vector<string> >dp, unordered_map<string, int> dp_mp, \
                unordered_map<string, bool> mp, string last, string endWord, \
                vector<string>& curr, vector<vector<string> >& ret)
    {
        if(isValid(endWord, last))
        {
            curr.push_back(endWord);
            if(0 == ret.size())
            {
                ret.push_back(curr);
            }
            else if(curr.size() < ret[0].size())
            {
                ret.clear();
                ret.push_back(curr);
            }
            else if(curr.size() == ret[0].size())
            {
                ret.push_back(curr);
            }

            curr.pop_back();
            return;
        }

        vector<string> sub = dp[dp_mp[last]];
        for(vector<string>::iterator tmp_iter = sub.begin(); tmp_iter != sub.end(); ++tmp_iter)
        {
            if(mp.find(*tmp_iter) == mp.end())
            {
                mp[*tmp_iter] = true;
                curr.push_back(*tmp_iter);
                solve(dp, dp_mp, mp, *tmp_iter, endWord, curr, ret);
                curr.pop_back();
                mp.erase(*tmp_iter);
            }
        }

    }

    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > ret;
        if(beginWord.length() == 0 || endWord.length() == 0 || wordList.size() == 0)
        {
            return ret;
        }

        if(isValid(beginWord, endWord))
        {
            vector<string> vec;
            vec.push_back(beginWord);
            vec.push_back(endWord);
            ret.push_back(vec);
        }

        unordered_set<string>::const_iterator iter;
        vector<vector<string> > dp;
        unordered_map<string, int> dp_mp;
        int cnt = 0;
        for(iter = wordList.begin(); iter != wordList.end(); ++iter)
        {
            dp_mp[*iter] = cnt++;
            vector<string> dp_sub;
            for(unordered_set<string>::const_iterator it = wordList.begin(); it != wordList.end(); ++it)
            {
                if(isValid(*iter, *it))
                {
                    dp_sub.push_back(*it);
                }
            }
            dp.push_back(dp_sub);
        }

        for(iter = wordList.begin(); iter != wordList.end(); ++iter)
        {
            vector<string> curr;
            unordered_map<string, bool> mp;
            unordered_set<string>::const_iterator it;
            string last = *iter;

            curr.push_back(beginWord);
            if(isValid(beginWord, *iter))
            {
                mp[*iter] = true;
                curr.push_back(*iter);
                solve(dp, dp_mp, mp, *iter, endWord, curr, ret);
                curr.pop_back();
                mp.erase(*iter);
            }
        }

        return ret;
    }
};

int main()
{
    string s1 = "hit";
    string s2 = "cog";
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("lot");
    wordList.insert("log");

    Solution sol;
    vector<vector<string> > result = sol.findLadders(s1, s2, wordList);
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
