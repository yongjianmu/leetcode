#include "../include/header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        int size = heights.size();
        if(0 == size)
        {
            return ret;
        }

        int cur_area = 0;
        stack<int> st;
        for(int i = 0; i < size; ++i)
        {
            while(!st.empty() && heights[i] <= heights[st.top()])
            {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                cur_area = h * width;
                ret = max(ret, cur_area);
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? size : size - st.top() - 1;
            ret = max(ret, h * width);
        }
        return ret;
    }
};

int main()
{
    //vector<int> input = {2, 1, 5, 6, 2, 3};
    vector<int> input = {9, 0};
    Solution sol;
    int result = sol.largestRectangleArea(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
