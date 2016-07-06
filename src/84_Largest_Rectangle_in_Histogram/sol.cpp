class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<int> q;
		 int n = heights.size();
		 int ans = 0;
		 for (int i = 0; i < n; i++){
			 while (!q.empty() && heights[q.top()] >= heights[i]){
				 int h = heights[q.top()];
				 q.pop();
				 int width = q.empty() ? i  : i - 1 - q.top();
				 if (width * h > ans) ans = h*width;
			 }
			 q.push(i);
		 }
 
		 while (!q.empty())
		 {
			 int h = heights[q.top()];
			 q.pop();
			 int width = q.empty() ? n : n - 1  - q.top();
			 if (width * h > ans) ans = h * width;
		 }
		 return ans;
    }
};
