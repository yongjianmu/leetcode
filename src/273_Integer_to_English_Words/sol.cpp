#include "../include/header.h"


/*
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
INT_MAX = 2,147,483,647
*/


string number1[]  = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string number2[]  = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string number3[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
    string getPart(int num)
    {
        if(0 == num)
        {
            return "";
        }

        cout << "getPart(): " << num << endl;
        string ret;
        int cnt = 1;
        int value1 = 0, value2 = 0, value3 = 0;

        while(0 != num)
        {
            int x = num % 10;
            switch(cnt)
            {
                case 1:
                    value1 = x;
                    break;
                case 2:
                    value2 = x;
                    if(1 == x)
                    {
                        ret.insert(0, number2[value1]);
                    }
                    else
                    {
                        if(0 != value1)
                        {
                            ret.insert(0, number1[value1]);
                        }

                        if(0 != value2)
                        {
                            if(0 != value1)
                            {
                                ret.insert(0, number3[value2] + " ");
                            }
                            else
                            {
                                ret.insert(0, number3[value2]);
                            }
                        }
                    }
                    break;
                case 3:
                    value3 = x;
                    if(0 != x)
                    {
                        if(0 != value1 || 0 != value2)
                        {
                            ret.insert(0, number1[value3] + " Hundred ");
                        }
                        else
                        {
                            ret.insert(0, number1[value3] + " Hundred");
                        }
                    }
                    break;
                default:
                    break;
            }
            ++cnt;
            num /= 10;
        }

        if(2 == cnt)
        {
            ret.insert(0, number1[value1]);
        }
        ret.erase(ret.find_last_not_of(" \n\r\t")+1);
        return ret;
    }

    string numberToWords(int num) {
        if(0 == num)
        {
            return "Zero";
        }

        string ret;
        int cur = 0;
        int cnt = 0;
        while(0 != num)
        {
            int x = num % 10;
            cur += x * pow(10, cnt % 3);
            cout << cur << endl;

            ++cnt;
            if(3 == cnt)
            {
                ret.insert(0, getPart(cur));
                cur = 0;
            }
            else if(6 == cnt)
            {
                if(0 != cur)
                {
                    ret.insert(0, getPart(cur) + " Thousand ");
                }
                cur = 0;
            }
            else if(9 == cnt)
            {
                if(0 != cur)
                {
                    ret.insert(0, getPart(cur) + " Million ");
                }
                cur = 0;
            }
            else if(12 == cnt)
            {
                if(0 != cur)
                {
                    ret.insert(0, getPart(cur) + " Billion ");
                }
                cur = 0;
            }
            num /= 10;
        }

        if(3 > cnt)
        {
            ret += getPart(cur);
        }
        else if(6 > cnt && 3 < cnt)
        {
            if(0 != cur)
            {
                ret.insert(0, getPart(cur) + " Thousand ");
            }
        }
        else if(9 > cnt && 6 < cnt)
        {
            if(0 != cur)
            {
                ret.insert(0, getPart(cur) + " Million ");
            }
        }
        else if(12 > cnt && 9 < cnt)
        {
            if(0 != cur)
            {
                ret.insert(0, getPart(cur) + " Billion ");
            }
        }

        ret.erase(ret.find_last_not_of(" \n\r\t")+1);
        return ret;
    }
};

int main()
{
    int input = 1000000;
    Solution sol;
    string result = sol.numberToWords(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
