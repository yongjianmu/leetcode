#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        unordered_map<int, bool> dict;
        int row = -1;
        int col = -1;
        vector<int> ret;

        int size = matrix.size();
        if(0 == size)
        {
            return ret;
        }

        int dir = 0;
        bool quit_flag = false;

        while(true)
        {
            if(0 == dir) // right, next is down
            {
                ++col;
                ++row;
                dir = 1;
                while(col < size)
                {
                    int point = row * 10 + col;
                    if(dict.find(point) == dict.end())
                    {
                        ret.push_back(matrix[row][col]);
                        dict[point] = true;
                        quit_flag = false;
                    }
                    else
                    {
                        if(quit_flag)
                        {
                            return ret;
                        }
                        quit_flag = true;
                        break;
                    }
                    ++col;
                }
            }
            else if(1 == dir) // down, next is left
            {
                --col;
                ++row;
                dir = 2;
                while(row < size)
                {
                    int point = row * 10 + col;
                    if(dict.find(point) == dict.end())
                    {
                        ret.push_back(matrix[row][col]);
                        dict[point] = true;
                        quit_flag = false;
                    }
                    else
                    {
                        if(quit_flag)
                        {
                            return ret;
                        }
                        quit_flag = true;
                        break;
                    }
                    ++row;
                }
            }
            else if(2 == dir) // left, next is up
            {
                --row;
                --col;
                dir = 3;
                while(0 <= col)
                {
                    int point = row * 10 + col;
                    if(dict.find(point) == dict.end())
                    {
                        ret.push_back(matrix[row][col]);
                        dict[point] = true;
                        quit_flag = false;
                    }
                    else
                    {
                        if(quit_flag)
                        {
                            return ret;
                        }
                        quit_flag = true;
                        break;
                    }
                    --col;
                }
            }
            else if(3 == dir) // up, next is right
            {
                ++col;
                --row;
                dir = 0;
                while(0 <= row)
                {
                    int point = row * 10 + col;
                    if(dict.find(point) == dict.end())
                    {
                        ret.push_back(matrix[row][col]);
                        dict[point] = true;
                        quit_flag = false;
                    }
                    else
                    {
                        if(quit_flag)
                        {
                            return ret;
                        }
                        quit_flag = true;
                        break;
                    }
                    --row;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;

    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);

    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(6);

    row3.push_back(7);
    row3.push_back(8);
    row3.push_back(9);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);
    
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "; ";
    }
    cout << endl;

    return 0;
}
