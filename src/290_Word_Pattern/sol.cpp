#include "../include/header.h"

/*
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
*/

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int len = pattern.length();
		vector<string> sp;
        size_t current;
        size_t next = -1;
        do
        {
            current = next + 1;
            next = str.find_first_of(" ", current);
            sp.push_back(str.substr(current, next - current));
        } while (next != string::npos);
		int size = sp.size();
		if (len != size)
		{
			return false;
		}

		unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < len; ++i)
        {
            if (mp1.find(pattern[i]) == mp1.end() && mp2.find(sp[i]) == mp2.end())
            {
                mp1[pattern[i]] = sp[i];
                mp2[sp[i]] = pattern[i];
            }
            else if (mp1[pattern[i]] == sp[i] && mp2[sp[i]] == pattern[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
	}
};

int main()
{
    string pattern = "abba";
    string str = "dog dog dog dog";
    Solution sol;
    bool result = sol.wordPattern(pattern, str);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}   