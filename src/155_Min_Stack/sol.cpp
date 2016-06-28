#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


class MinStack {
public:
    vector<int> mList;
    vector<int>::iterator mIter;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        mList.push_back(x);
    }
    
    void pop() {
        if(0 < mList.size())
        {
            mList.erase(mList.end() - 1);
        }
    }
    
    int top() {
        if(0 < mList.size())
        {
            return *mList.rbegin();
        }
        return 0;
    }
    
    int getMin() {
        if(0 < mList.size())
        {
            int ret = mList[0];
            for(mIter = mList.begin(); mIter != mList.end(); ++mIter)
            {
                ret = min(ret, *mIter);
            }
            return ret;
        }
        return 0;
    }
};

int main()
{
    return 0;
}
