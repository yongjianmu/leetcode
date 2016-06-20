#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt_tmp = 0;
        int size1 = nums1.size();
        vector<int> tmp;
        for(int i = 0; i < m; ++i)
        {
            tmp.push_back(nums1[i]);
        }

        while(cnt1 < m + n)
        {
            if(cnt_tmp < m && cnt2 < n)
            {
                if(tmp[cnt_tmp] >= nums2[cnt2])
                {
                    nums1[cnt1] = nums2[cnt2];
                    ++cnt2;
                }
                else
                {
                    nums1[cnt1] = tmp[cnt_tmp];
                    ++cnt_tmp;
                }
            }
            else if(cnt_tmp < m)
            {
                nums1[cnt1] = tmp[cnt_tmp];
                ++cnt_tmp;
            }
            else
            {
                nums1[cnt1] = nums2[cnt2];
                ++cnt2;
            }
            ++cnt1;
        }
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(0);

    nums2.push_back(2);

    Solution sol;
    sol.merge(nums1, 1, nums2, 1);
    for(int i = 0; i < nums1.size(); ++i)
    {
        cout << nums1[i] << ", ";
    }
    cout << endl;

    return 0;
}
