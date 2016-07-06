//
//  main.cpp
//  79_Word_Search
//
//  Created by Yongjian Mu on 16/3/8.
//  Copyright © 2016年 Yongjian Mu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long mRow, mStrSize;
    bool mRet;
    int mDirRow[4], mDirCol[4];
    bool find(vector<vector<char>>& board, string word, long curRow, long curCol, long curStr)
    {
        if(curStr == mStrSize)
        {
            return true;
        }
        
        for(int i = 0; i < 4; ++i)
        {
            if(curRow + mDirRow[i] < mRow && curCol + mDirCol[i] <  board[curRow].size()\
               && board[curRow + mDirRow[i]][curCol + mDirCol[i]] == word[curStr + 1] \
               )
            {
                if(true == find(board, word, curRow + mDirRow[i], curCol + mDirCol[i], curStr + 1))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        mRow = board.size();
        if(word.size() == 0 || mRow == 0)
        {
            return false;
        }
        
        mStrSize = word.size();
        if(0 == mStrSize)
        {
            return false;
        }
        
        mDirRow[0] = 1;
        mDirRow[1] = -1;
        mDirRow[2] = 0;
        mDirRow[3] = 0;
        mDirCol[0] = 0;
        mDirCol[1] = 0;
        mDirCol[2] = 1;
        mDirCol[3] = -1;
        
        for(int i = 0; i < mRow; ++i)
        {
            for(int j = 0; j < board[mRow].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    if(find(board, word, i, j, 0) == true)
                    {
                        mRet = true;
                        break;
                    }
                }
            }
        }
        
        return mRet;
    }
};

int main(int argc, const char * argv[])
{
    vector<vector<char>> board;
    vector<char> vec1;
    vector<char> vec2;
    vector<char> vec3;
    vector<char> vec4;
    
    vec1.push_back('A');
    vec1.push_back('B');
    vec1.push_back('C');
    vec1.push_back('E');
    board.push_back(vec1);
   
    vec2.push_back('F');
    vec2.push_back('S');
    vec2.push_back('C');
    vec2.push_back('S');
    board.push_back(vec2);
    
    vec3.push_back('A');
    vec3.push_back('D');
    vec3.push_back('E');
    vec3.push_back('E');
    board.push_back(vec3);
    
    vec2.push_back('A');
    vec2.push_back('B');
    vec2.push_back('C');
    vec2.push_back('C');
    vec2.push_back('E');
    board.push_back(vec4);
    
    cout << "Hello" << endl;
    
    return 0;
}
