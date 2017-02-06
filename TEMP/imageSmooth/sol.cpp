#include "../../second/include/header.h"

/*
例如原始矩阵是这样的： 
a b c d 
e f g h 
i j k l 
m n o p 
然后先跑一轮，将矩阵变成 
a+e b+f c+g d+h 
a+e+i b+f+j c+g+k d+h+l 
e+i+m f+j+n g+k+o h+l+p 
i+m j+n k+o l+p 
如此，每个cell的结果就是只跟本行cell值相关，与上下行cell无关了。只要用两个临时变量就够了。 想得到如上矩阵，需要纵向计算。这样与左右列的cell也无关。
同样只要用两个临时变量就够了。in place搞定，不过要多跑一轮。

!! Overflow & not in place !!
*/

void smooth(vector<vector<int> >& matrix)
{
    int row = matrix.size();
    if(0 == row) return;
    int col = matrix[0].size();
    if(0 == col) return;

    vector<int> curRow, lastRow;
    for(int i = 0; i < row; ++i)
    {
        lastRow.swap(curRow);
        curRow.clear();
        curRow.insert(curRow.begin(), matrix[i].begin(), matrix[i].end());
        for(int j = 0; j < col; ++j)
        {
            long long cnt = 1;
            long long sum = matrix[i][j];
            if(i > 0)
            {
                sum += lastRow[j];
                ++cnt;
                if(j > 0) 
                {
                    sum += lastRow[j - 1];
                    ++cnt;
                }
                if(j < col - 1) 
                {
                    sum += lastRow[j + 1];
                    ++cnt;
                }
            }
            if(i < row - 1)
            {
                sum += matrix[i + 1][j];
                ++cnt;
                if(j > 0)
                {
                    sum += matrix[i + 1][j - 1];
                    ++cnt;
                }
                if(j < col - 1)
                {
                    sum += matrix[i + 1][j + 1];
                    ++cnt;
                }
            }
            if(j > 0)
            {
                sum += curRow[j - 1];
                ++cnt;
            }
            if(j < col - 1)
            {
                sum += curRow[j + 1];
                ++cnt;
            }
            cout << "sum: " << sum << " cnt: " << cnt << endl;
            matrix[i][j] = static_cast<int> (sum / cnt);
        }
    }
}

// Optimize, use one vector + one temp var, instead of two vectors
void smooth2(vector<vector<int> >& matrix)
{
    int row = matrix.size();
    if(0 == row) return;
    int col = matrix[0].size();
    if(0 == col) return;

    vector<int> lastRow(col, 0);
    int tempLast = 0;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            long long sum = matrix[i][j], cnt = 1;
            if(i > 0)
            {
                sum += lastRow[j];
                ++cnt;
                if(j > 0)
                {
                    sum += tempLast;
                    ++cnt;
                }
                if(j < col - 1)
                {
                    sum += lastRow[j + 1];
                    ++cnt;
                }
            }
            if(i < row - 1)
            {
                sum += matrix[i + 1][j];
                ++cnt;
                if(j > 0)
                {
                    sum += matrix[i + 1][j - 1];
                    ++cnt;
                }
                if(j < col - 1)
                {
                    sum += matrix[i + 1][j + 1];
                    ++cnt;
                }
            }
            if(j > 0)
            {
                sum += lastRow[j - 1];
                ++cnt;
            }
            if(j < col - 1)
            {
                sum += matrix[i][j + 1];
                ++cnt;
            }
            cout << "sum: " << sum << " cnt: " << cnt << endl;
            tempLast = lastRow[j];
            lastRow[j] = matrix[i][j];
            matrix[i][j] = static_cast<int> (sum / cnt);
        }
    }
}

int main()
{
    vector<vector<int> > matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    smooth(matrix);
    printResult();
    printVector2D(matrix);

    vector<vector<int> > matrix2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    smooth2(matrix2);
    printResult();
    printVector2D(matrix2);

    return 0;
}
