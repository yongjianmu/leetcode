#include "../include/header.h"

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
*/

class Stack {
public:
    queue<int> mQ1, mQ2;
    // Push element x onto stack.
    void push(int x) {
        if(!mQ1.empty())
        {
            mQ1.push(x);
        }
        else
        {
            mQ2.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(mQ1.empty())
        {
            while(!mQ2.empty())
            {
                int a = mQ2.front();
                mQ2.pop();
                if(!mQ2.empty())
                {
                    mQ1.push(a);
                }
            }
        }
        else
        {
            while(!mQ1.empty())
            {
                int a = mQ1.front();
                mQ1.pop();
                if(!mQ1.empty())
                {
                    mQ2.push(a);
                }
            }
        }
    }

    // Get the top element.
    int top() {
        int ret = 0;
        if(mQ1.empty())
        {
            while(!mQ2.empty())
            {
                int a = mQ2.front();
                mQ2.pop();
                mQ1.push(a);
                if(mQ2.empty())
                {
                    ret = a;
                }
            }
        }
        else
        {
            while(!mQ1.empty())
            {
                int a = mQ1.front();
                mQ1.pop();
                mQ2.push(a);
                if(mQ1.empty())
                {
                    ret = a;
                }
            }
        }
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return mQ1.empty() && mQ2.empty();
    }
};

int main()
{
    Stack sol;
    sol.push(1);
    cout << sol.top() << endl;

    return 0;
}
