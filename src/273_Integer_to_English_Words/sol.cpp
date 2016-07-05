#include "../include/header.h"


/*
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
INT_MAX = 2,147,483,647
*/


class Solution {
public:
    string getPart(int num)
    {
    }

    string numberToWords(int num) {
        if(0 == num)
        {
            return "Zero";
        }

        string number1[]  = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string number2[]  = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string number3[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string digit[] = {"", "", "", "Hundred", "Thousand", "", "", "", "Million"};

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
                        ret.insert(0, " " + number1[value1]);
                        ret.insert(0, number3[value2]);
                    }
                    break;
                case 3:
                    break;
                default:
                    break;
            }
            ++cnt;
        }
    }
};

int main()
{
    return 0;
}
