#include "../include/header.h"

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if(n < 4) return false;
        int t1 = 0,t2 = x[0],t3 = x[1],t4 = x[2],t5;
        bool increase = t4 > t2? true:false;
        for(int i=3;i<n;i++){
            t5 = x[i];
            if(increase && t3 >= t5){
                if(t5 + t1 <t3 || i + 1 <n && x[i+1] + t2 < t4)
                    increase = false;
                else if (i + 1 <n)
                    return true;
            }
            else if(!increase && t3 <= t5)
                return true;
            t1 = t2;
            t2 = t3;
            t3 = t4;
            t4 = t5;
        }
        return false;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4};
    Solution sol;
    bool result = sol.isSelfCrossing(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
