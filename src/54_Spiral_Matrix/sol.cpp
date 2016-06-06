#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        unordered_map<pair<int, int>, bool> dict;
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
                while(col < size)
                {
                    pair<int, int> point = make_pair(row, col);
                    if(dict.find(point) != dict.end())
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
                        dir = 1;
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
                while(row < size)
                {
                    pair<int, int> point = make_pair(row, col);
                    if(dict.find(point) != dict.end())
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
                        dir = 2;
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
                while(0 <= col)
                {
                    pair<int, int> point = make_pair(row, col);
                    if(dict.find(point) != dict.end())
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
                        dir = 3;
                        quit_flag = true;
                        break;
                    }
                }
            }
            else if(3 == dir) // up, next is right
            {
                ++col;
                --row;
                while(0 <= row)
                {
                    pair<int, int> point = make_pair(row, col);
                    if(dict.find(point) != dict.end())
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
                        dir = 0;
                        quit_flag = true;
                        break;
                    }
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
