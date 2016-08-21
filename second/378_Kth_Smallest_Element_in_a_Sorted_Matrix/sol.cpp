#include "../include/header.h"

/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
*/

struct Node
{
    int val;
    int x;
    int y;

    Node(int v, int i, int j) : val(v), x(i), y(j) {}

    bool operator < (const Node& a) const
    {
        return val >= a.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        priority_queue<Node> q;
        Node node(matrix[0][0], 0, 0);
        q.push(node);
        --k;
        while(k > 0)
        {
            Node tmp = q.top();
            q.pop();
            if(tmp.x == 0 && tmp.y < col - 1)
            {
                Node tmp1(matrix[tmp.x][tmp.y + 1], tmp.x, tmp.y + 1);
                q.push(tmp1);
            }
            if(tmp.x < row - 1)
            {
                Node tmp2(matrix[tmp.x + 1][tmp.y], tmp.x + 1, tmp.y);
                q.push(tmp2);
            }
            --k;
        }

        return q.top().val;
    }
};

int main()
{
    vector<vector<int> > input = {
        {1, 3, 5},
        {6, 7, 12},
        {11, 14, 14}
    };
    int k = 6;
    Solution sol;
    int result = sol.kthSmallest(input, k);
    printResult();
    cout << result << endl;

    return 0;
}
