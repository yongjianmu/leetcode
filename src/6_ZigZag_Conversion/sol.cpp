/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display t * his pattern in a fixed font for better legibility)

 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * *********************************************************
 * Solution:
 *
 * nRows = 2
 * 0 2 4 6 ...
 * 1 3 5 7
 *
 * nRows = 3
 * 0   4   8  ...
 * 1 3 5 7 9
 * 2   6   10
 *
 * nRows = 4
 * 0     6       12 ...
 * 1   5 7    11
 * 2 4   8 10  
 * 3     9
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if(1 >= numRows)
        {
            return s;
        }

        int zig_size = 2 * numRows - 2;
        int input_size = s.size();
        string ret; 
        for(int i = 0; i < numRows; ++i)
        {
            int j = i;
            while(j < input_size)
            {
                ret.append(1, s[j]); /*Eg nRows = 3, [0, 4, 8], [1, 5, 9], [2, 6, 10]*/

                /* Other rows expect the first and last, add the middle number */
                if(0 < i && numRows - 1 > i)
                {
                    int mid_num = j + zig_size - (2 * i);
                    if(mid_num < input_size)
                    {
                        ret.append(1, s[mid_num]);
                    }
                }
                j += zig_size;
            }
        }
        return ret;
    }
};

int main()
{
    string input = "PAYPALISHIRING";
    int row = 3;
    Solution sol;

    cout << "Original: " << input << endl;
    cout << "Convert: " << sol.convert(input, row) << endl;

    return 0;
}
