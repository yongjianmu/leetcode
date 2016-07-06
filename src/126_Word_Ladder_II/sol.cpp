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
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > ret;
        if(beginWord.length() == 0 || endWord.length() == 0 || wordList.size() == 0)
        {
            return ret;
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
