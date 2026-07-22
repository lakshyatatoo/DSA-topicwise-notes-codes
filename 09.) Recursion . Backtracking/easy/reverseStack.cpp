#include <bits/stdc++.h>
using namespace std;

// brute
// array method to reverse the stack

// optimal no exteral
void insertElements(stack<int> &st, int x)
{

    if (st.empty())
    {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertElements(st, x);
    st.push(temp);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int x = st.top();
    st.pop();

    reverseStack(st);
    insertElements(st, x);
}