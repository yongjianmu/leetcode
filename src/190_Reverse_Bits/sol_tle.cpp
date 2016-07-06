#include "../include/header.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        vector<int> vec;

        uint32_t divider = n;
        while(true)
        {
            if(1 == divider)
            {
                vec.push_back(divider);
                break;
            }

            int reminder = divider % 2;
            vec.push_back(reminder);
            divider /= 2;
        }

        //for(int i = 0; i < vec.size(); ++i)
        //{
        //    cout << vec[i] << ", ";
        //}
        //cout << endl;
        int size = vec.size();
        for(int i = 0; i < size; ++i)
        {
            if(1 == vec[i])
            {
                //cout << pow(2, 32 - 1 - i) << ", ";
                ret += static_cast<uint32_t> (pow(2, 32 - 1 - i));
            }
            else
            {
                //cout << 0 << ", ";
            }
        }
        //cout << endl;
        return ret;
    }
};

int main()
{
    uint32_t input = 43261596;
    //uint32_t input = 8;
    Solution sol;
    uint32_t result = sol.reverseBits(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
