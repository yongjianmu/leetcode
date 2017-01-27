#include "../include/header.h"

class Solution {
public:
    int magicalString(int n) {
        string str = "122";
        int index = 2;
        while(str.size()<n)
        {
            int next = (str.back()-'0') ^ 3;//
            cout << next << endl;
            str.push_back('0'+next);
            if(str[index++]=='2') str.push_back('0'+next);
        }
        cout << str << endl;
        int result = 0;
        for(int i=0;i<n;i++){
            if(str[i]=='1')result ++;
        }
        return result;
        
    }
};

int main()
{
    int n = 6;
    Solution sol;
    int result = sol.magicalString(n);
    printResult();
    cout << result << endl;
    return 0;
}
