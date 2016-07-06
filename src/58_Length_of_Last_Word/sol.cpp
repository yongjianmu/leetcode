#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
   int lengthOfLastWord(string s) {
       int cnt = 0;
       if(0 == s.size())
       {
           return cnt;
       }

       if(0 == s.compare(" "))
       {
           return cnt;
       }

       string::iterator iter;
       iter = s.end();
       --iter;
       for(; iter != s.begin(); --iter)
       {
           if(' ' != *iter)
           {
               ++cnt;
           }
           else
           {
               if(*iter == s.at(s.size() - 1))
               {
                   continue;
               }
               else
               {
                   break;
               }
           }
       }

       if(iter == s.begin() && *iter != ' ')
       {
           ++cnt;
       }

       return cnt;
   }
};

int main()
{
    Solution sol;
    string s("b a ");

    cout << sol.lengthOfLastWord(s) << endl;
    return 0;
}
