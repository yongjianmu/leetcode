#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int length = nums.size() - 1;
    if(0 == length)
    {
        return;
    }
    while( length > 0 ){
        if( nums[ length - 1 ] < nums[ length ] )
            break;
        length --;
    }
    if( length == 0 ){
        for( int i = 0, j = nums.size()-1; i < j; i++ ,j-- )
            swap( nums[ i ], nums[ j ] );
    }


    int k = nums.size() - 1;
	int pos = k;
    for( ; k >= length; k-- )
        if( nums[ k ] > nums[ length - 1 ] )
		{
			if(nums[pos] < nums[k])
			{
				pos = k;
			}
           // break;
		}
    swap( nums[pos], nums[ length - 1 ] );
    sort( nums.begin() + length , nums.end() );
    }
};

int main()
{
	Solution sol;
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	
	vector<int>::iterator iter;
	for(iter = num.begin(); iter != num.end(); ++iter)
	{
		cout << *iter << endl;
	}

	sol.nextPermutation(num);
	
	for(iter = num.begin(); iter != num.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}
