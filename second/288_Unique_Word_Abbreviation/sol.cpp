#include "../include/header.h"

class ValidWordAbbr {
public:
    unordered_map<string, int> mUmp;
    unordered_map<string, bool> mDict;
    ValidWordAbbr(vector<string> &dictionary) {
        for(string str : dictionary)
        {
            int size = str.length();
            if(2 >= size)
            {
                continue;
            }
            
            mDict[str] = true;
            if(1 == size)
            {
                mUmp[str] = 1;
            }
            else
            {
                string cur;
                cur.push_back(str[0]);
                cur.push_back(str[size - 1]);
                mUmp[cur] = size - 2;
            }
        }
    }

    bool isUnique(string word) {
        int size = word.length();
        
        if(2 >= size)
        {
            return true;
        }
        
        string cur;
        cur.push_back(word[0]);
        cur.push_back(word[size - 1]);
        int value = size - 2;
        
        if(mDict.find(word) != mDict.end())
        {
            return false;
        }
        
        auto iter = mUmp.find(cur);
        if(iter == mUmp.end())
        {
            return true;
        }
        
        return iter->second != value;
    }
};

int main()
{
    vector<string> dict = {"dog"};
    ValidWordAbbr sol(dict);
    bool result = sol.isUnique("dig");
    printResult();
    cout << result << endl;

    return 0;
}
