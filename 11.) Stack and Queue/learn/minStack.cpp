#include <bits/stdc++.h>
using namespace std;

// brute
// tc=O(1)
// sc=O(2n)
class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

// optimal
// tc=O(1) for all operations
// sc=O(n)
class MinStack
{
public:
    stack<long long> st;
    long long mini = LONG_MAX;
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else
        {
            if (val >= mini)
            {
                st.push(val);
            }
            else
            {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long x = st.top();
        if (x < mini)
        {
            mini = 2LL * mini - x;
        }
        st.pop();
        if (st.empty())
        {
            mini = LONG_MAX;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long x = st.top();
        if (x < mini)
            return mini;
        else
            return (int)x;
    }

    int getMin() { return (int)mini; }
};
