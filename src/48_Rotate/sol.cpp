#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix){
		int n = matrix.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - i - 1; j++)
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		reverse(matrix.begin(), matrix.end());
	}
};

int main()
{
    vector<vector<int> > input;
    vector<int> r1;
    vector<int> r2;
    vector<int> r3;
    vector<int> r4;

    r1.push_back(1);
    r1.push_back(2);
    r1.push_back(3);
    r1.push_back(4);

    r2.push_back(1);
    r2.push_back(2);
    r2.push_back(3);
    r2.push_back(4);

    r3.push_back(1);
    r3.push_back(2);
    r3.push_back(3);
    r3.push_back(4);

    r4.push_back(1);
    r4.push_back(2);
    r4.push_back(3);
    r4.push_back(4);

    input.push_back(r1);
    input.push_back(r2);
    input.push_back(r3);
    input.push_back(r4);
    
    reverse(input.begin(), input.end());

    Solution sol;
    sol.rotate(input);

    int n = input.size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << input[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
