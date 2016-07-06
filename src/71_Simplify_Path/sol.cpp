#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

class Solution {
public:
	vector<string> split(const string &s, char delim) {
    	stringstream ss(s);
    	string item;
    	vector<string> tokens;
    	while (getline(ss, item, delim)) {
        	tokens.push_back(item);
    	}
    	return tokens;
	}

    string simplifyPath(string path) {
        string ret = "";
		if(0 == path.length())
		{
			return ret;
		}

		vector<string> tmp;
		tmp = split(path, '/');
		cout << endl;
		int cnt = 0;
		vector<string>::reverse_iterator riter;
		for(riter = tmp.rbegin(); riter != tmp.rend() - 1; ++riter)
		{
			if("." == *riter || "" == *riter)
			{
				continue;
			}
			else if(".." == *riter)
			{
				++cnt;
				continue;
			}
			else
			{
				if(0 < cnt)
				{
					--cnt;
					continue;
				}
				else
				{
					ret = "/" + *riter + ret;
				}
			}
		}

		if("" == ret)
		{
			ret += "/";
		}
		return ret;
    }
};

int main()
{
	string input = "///";
	Solution sol;
	cout << "**** Solution ****" << endl;
	cout << sol.simplifyPath(input) << endl;
	return 0;
}
