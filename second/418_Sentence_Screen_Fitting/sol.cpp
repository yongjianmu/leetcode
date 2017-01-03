#include "../include/header.h"


class Solution {
public:
    int countByStart(int start, int size, vector<string> sentence, int cols)
    {
        int cnt = 0;
        while(cols >= 0)
        {
            int len = sentence[start].length();
            if(cols >= len)
            {
                cols -= len + 1;
                ++cnt;
            }
            else
            {
                break;
            }
            start = (start + 1) % size;
        }
        return cnt;
    }
    
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int size = sentence.size();
        unordered_map<int, int> ump;
        for(int i = 0; i < size; ++i)
        {
            ump[i] = countByStart(i, size, sentence, cols);
            cout << i << ", " << ump[i] << endl;
        }
        
        int total = 0, pos = 0;
        for(int i = 0; i < rows; ++i)
        {
            int cur = ump[pos];
            total += cur;
            pos = (pos + cur) % size;
        }
        
        cout << total << endl;
        return total / size;
    }
};

int main()
{
    vector<string> input = {"I","had","apple","pie"};
    int rows = 4;
    int cols = 5;
    Solution sol;
    int result = sol.wordsTyping(input, rows, cols);
    printResult();
    cout << result << endl;

    return 0;
}
