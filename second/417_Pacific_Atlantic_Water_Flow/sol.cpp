#include "../include/header.h"


class Solution {
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
        int row = matrix.size(), col = 0 == row ? 0 : matrix[0].size();
        vector<pair<int, int> > ret;
        if(row == 0 || col == 0)
        {
            return ret;
        }
        
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
        // Use BFS to calc pacific nodes, and add to hash
        unordered_map<int, bool> pacificUmp;
        queue<pair<int, int> > pacificQueue;
        for(int i = 0; i < col; ++i)
        {
            pacificQueue.push(make_pair(0, i));
            pacificUmp[i] = true;
        }
        for(int i = 0; i < row; ++i)
        {
            if(pacificUmp.find(i * col) == pacificUmp.end())
            {
                pacificQueue.push(make_pair(i, 0));
                pacificUmp[i * col] = true;
            }
        }
        
        while(!pacificQueue.empty())
        {
            pair<int, int> node = pacificQueue.front(); pacificQueue.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nx = node.first + dx[i], ny = node.second + dy[i];
                if(nx < 0 || nx >= row || ny < 0 || ny >= col || pacificUmp.find(nx * col + ny) != pacificUmp.end())
                {
                    continue;
                }
                //cout << "root: " << node.first << ", " << node.second << "  new: " << nx << ", " << ny << endl;
                if(matrix[nx][ny] >= matrix[node.first][node.second])
                {
                    pacificUmp[nx * col + ny] = true; pacificQueue.push(make_pair(nx, ny));
                }
            }
        }
        
        // calc Atlantic
        unordered_map<int, bool> atlanticUmp;
        queue<pair<int, int> > atlanticQueue;
        for(int i = 0; i < col; ++i)
        {
            atlanticQueue.push(make_pair(row - 1, i));
            atlanticUmp[(row - 1) * col + i] = true;
        }
        for(int i = 0; i < row; ++i)
        {
            if(atlanticUmp.find(i * col + col - 1) == atlanticUmp.end())
            {
                atlanticQueue.push(make_pair(i, col - 1));
                atlanticUmp[i * col + col - 1] = true;
            }
        }
        
        while(!atlanticQueue.empty())
        {
            pair<int, int> node = atlanticQueue.front(); atlanticQueue.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nx = node.first + dx[i], ny = node.second + dy[i];
                if(nx < 0 || nx >= row || ny < 0 || ny >= col || atlanticUmp.find(nx * col + ny) != atlanticUmp.end())
                {
                    continue;
                }
                if(matrix[nx][ny] >= matrix[node.first][node.second])
                {
                    atlanticUmp[nx * col + ny] = true; atlanticQueue.push(make_pair(nx, ny));
                }
            }
        }
        
        // output result
        for(auto iter = atlanticUmp.begin(); iter != atlanticUmp.end(); ++iter)
        {
            if(pacificUmp.find(iter->first) != pacificUmp.end())
            {
                ret.push_back(make_pair(iter->first / col, iter->first % col));
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > input = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    Solution sol;
    vector<pair<int, int> >result = sol.pacificAtlantic(input);
    printResult();
    for(auto node : result)
    {
        cout << node.first << ", " << node.second << endl;
    }

    return 0;
}
