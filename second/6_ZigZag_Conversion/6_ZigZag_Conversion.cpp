// 6_ZigZag_Conversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/header.h"

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

class Solution {
public:
    string convert(string s, int numRows) {
        const int size = s.size();
        if (numRows == 1) {
            return s;
        }

        int distance, distance2;
        string ret;
        for (int i = 0; i < numRows; ++i) {
            distance = 2 * (numRows - 1);
            distance2 = i ? distance - (2 * i) : 0;

            for (int j = i; j < size; j += distance) {
                ret.push_back(s[j]);
                if (distance2 && j + distance2 < size) {
                    ret.push_back(s[j + distance2]);
                }
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
    string result = sol.convert(input, row);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}

