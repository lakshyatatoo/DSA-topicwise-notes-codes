#include <bits/stdc++.h>
using namespace std;

//brute
void sortStack(stack<int> &st)
{

    vector<int> arr;

    while (!st.empty())
    {
        arr.push_back(st.top());
        st.pop();
    }

    sort(arr.begin(), arr.end());

    for (int x : arr)
    {
        st.push(x);
    }
}
//brute recursion
void insertSorted(stack<int> &st, int x)
{
    if (st.empty() || st.top() <= x)
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertSorted(st, x);

    st.push(temp);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int x = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, x);
}