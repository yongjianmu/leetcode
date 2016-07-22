#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;


template <class T>
void printVector1D(vector<T> vec, bool separate_line = false)
{
    cout << "#### Result ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(separate_line)
        {
            cout << vec[i] << endl;
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
    cout << endl;
}

template <class T>
void printVector2D(vector<vector<T> > vec, bool separate_line = false)
{
    cout << "#### Result ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].size(); ++j)
        {
            if(separate_line)
            {
                cout << vec[i][j] << endl;
            }
            else
            {
                cout << vec[i][j] << ", ";
            }
        }
        cout << "#####################" << endl;
    }
}

void printVectorInt1(vector<int> vec)
{
    cout << "#### Result ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ", ";
    }
    cout << endl;
}

void printVectorStr1(vector<string> vec)
{
    cout << "#### Result ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
    }
}

void printVectorInt2(vector<vector<int> > vec)
{
    cout << "#### Result ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[0].size(); ++j)
        {
            cout << vec[i][j] << ", ";
        }
        cout << endl;
    }
}

void printVectorStr2(vector<vector<string> > vec)
{
    cout << "#### Result ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[0].size(); ++j)
        {
            cout << vec[i][j] << endl;
        }
        cout << "#####################" << endl;
    }
}
