#include "../include/header.h"

vector<int> getNthPermutation(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> ret;
    vector<int> f(n, 1);
    for(int i = 1; i < n; ++i)
    {
        f[i] = i * f[i - 1];
    }
    --k;

    for(int i = n; i >= 1; --i)
    {
        int j = k / f[i - 1];
        k %= f[i - 1];
        ret.push_back(nums[j]);
        nums.erase(nums.begin() + j);
    }
    return ret;
}

vector<int> shuffle(vector<int> nums)
{
    int n = nums.size();
    int k = 1 + rand() % n;
    return getNthPermutation(nums, k);
}

int main()
{
    srand(time(NULL));
    vector<int> input = {1,2,3,4,5};
    vector<int> result = shuffle(input);
    printResult();
    printVector1D(result);

    return 0;
}
