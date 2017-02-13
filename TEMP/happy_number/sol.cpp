class Solution {
public:
    bool isHappy(int n) {
        if(0 >= n) return false;
        int sum = n;
        while(true)
        {
            if(1 == sum) return true;
            else if(4 == sum) return false;
            else
            {
                int temp = 0;
                while(sum > 0)
                {
                    temp += pow((sum % 10), 2);
                    sum /= 10;
                }
                sum = temp;
            }
        }
        return true;
    }
};
