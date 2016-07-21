#include "../include/header.h"

/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

class Solution {
public:
    vector<string> ret;

    void fillResult(int start_pos, int end_pos, vector<string>& words, int maxWidth, int char_len, bool last_row)
    {
        int num = end_pos - start_pos;

        if(last_row)
        {
            string cur = "";
            for(int j = start_pos; j <= end_pos; ++j)
            {
                cur += words[j];
                if(j < end_pos)
                {
                    cur += " ";
                }
            }
            string tmp(maxWidth - cur.length(), ' ');
            cur += tmp;
            ret.push_back(cur);
            return;
        }

        if(0 == num)
        {
            string cur = words[start_pos];
            string sp(maxWidth - cur.length(), ' ');
            cur += sp;
            ret.push_back(cur);
            return;
        }

        int space_left = maxWidth - char_len;
        //cout << 4 << ": " << space_left << ", " << num << endl;
        int k = space_left % num;
        int l = space_left / num;
        //cout << 5 << ": " << k << ", " << l << endl;


        vector<string> space;
        for(int j = 0; j < num; ++j)
        {
            if(j < k)
            {
                string tmp(l + 1, ' ');
                space.push_back(tmp);
            }
            else
            {
                string tmp(l, ' ');
                space.push_back(tmp);
            }
        }

        string cur_str = "";

        for(int j = start_pos; j <= end_pos; ++j)
        {
            cur_str += words[j];
            if(j < end_pos)
            {
                //cout << space[j - start_pos].length() << endl;
                cur_str += space[j - start_pos];
            }
        }
        ret.push_back(cur_str);
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        if(0 == size)
        {
            return ret;
        }

        int row_len = 0, char_len = 0;
        int start_pos = 0;
        for(int i = 0; i < size; )
        {
            int cur_len = words[i].length();
            if(0 == row_len && cur_len <= maxWidth)
            {
                row_len = cur_len;
                char_len = cur_len;
                if(i == size - 1)
                {
                    fillResult(start_pos, i, words, maxWidth, char_len, true);
                }
                ++i;
            }
            else if(cur_len + row_len + 1 <= maxWidth)
            {
                row_len += cur_len + 1;
                char_len += cur_len;
                //cout << 2 << ": " << row_len << endl;
                if(i == size - 1)
                {
                    fillResult(start_pos, i, words, maxWidth, char_len, true);
                }
                ++i;
            }
            else /* Cannot put in one line, fill current line */
            {
                int end_pos = i - 1;
                //cout << 3 << ": " << start_pos << ", " << end_pos << endl;
                fillResult(start_pos, end_pos, words, maxWidth, char_len, false);
                row_len = 0;
                char_len = 0;
                start_pos = i;
            }
        }
        return ret;
    }
};

int main()
{
    //vector<string> input = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> input = {"What","must","be","shall","be."};
    int maxWidth = 12;
    Solution sol;
    vector<string> result = sol.fullJustify(input, maxWidth);
    printVectorStr1(result);

    return 0;
}
