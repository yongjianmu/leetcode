class Solution {
public:
    bool mRet;
    
    void solve(int cur_sum, int pos, vector<int>& nums, int sum, int size)
    {
        if(cur_sum == sum)
        {
            mRet = true;
            return;
        }
        
        if(pos >= size || cur_sum > sum)
        {
            return;
        }
        
        solve(cur_sum + nums[pos], pos + 1, nums, sum, size);
        solve(cur_sum, pos + 1, nums, sum, size);
    }

    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if(1 >= size)
        {
            return false;
        }
        
        mRet = false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
        {
            return false;
        }
        
        sum /= 2;
        int cur_sum = nums[0];
        solve(cur_sum, 1, nums, sum, size);
        return mRet;
    }
};
