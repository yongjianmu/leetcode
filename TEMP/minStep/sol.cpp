#include "../../second/include/header.h"

void findNexts(vector<vector<int> >& maze, int rows, int cols, pair<int, pair<int, int> >& node, queue<pair<int, pair<int, int> > >& nodes) {
    int x = node.first;
    int y = node.second.first;
    int val = node.second.second;
    maze[x][y] = 1;

    if (x - 1 >= 0 && maze[x - 1][y] == 0)
        nodes.push({x - 1, {y, val + 1}});

    if (x + 1 < rows && maze[x + 1][y] == 0)
        nodes.push({x + 1, {y, val + 1}});

    if (y - 1 >= 0 && maze[x][y - 1] == 0)
        nodes.push({x, {y - 1, val + 1}});

    if (y + 1 < cols && maze[x][y + 1] == 0)
        nodes.push({x, {y + 1, val + 1}});
}

int findMinSteps(vector<vector<int> >& maze, int rows, int cols, int exitRow, int exitCol) {
    if (rows < 1 || cols < 1 || exitRow < 0 || exitCol < 0 || exitRow >= rows || exitCol >= cols || maze[0][0] == 1)
        return -1;

    queue<pair<int, pair<int, int> > > myQueue;
    myQueue.push({0, {0, 0}});

    while (!myQueue.empty()) {
        auto current = myQueue.front();
        myQueue.pop();

        if (current.first == exitRow && current.second.first == exitCol)
            return current.second.second;

        findNexts(maze, rows, cols, current, myQueue);
    }

    return -1;
}


int main() {
    vector<vector<int> > arr =
            {
                    {0,0,0,0},
                    {0,1,0,0},
                    {0,0,0,0}
            };

    int steps = findMinSteps(arr, 3, 4, 1, 3);
    cout << steps << endl;
    return 0;
}
