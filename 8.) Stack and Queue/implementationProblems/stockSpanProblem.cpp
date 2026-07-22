#include <bits/stdc++.h>
using namespace std;

// brute - search for each element till start of list
class StockSpanner
{
public:
    vector<int> arr;
    StockSpanner()
    {
    }

    int next(int price)
    {
        arr.push_back(price);
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] <= price)
                cnt++;
            else
                break;
        }
        return cnt;
    }
};

// optimal - use stack to store the index of the previous greater element
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int ind = -1;
    int ans = 0;
    StockSpanner()
    {
    }

    int next(int price)
    {
        ind++;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};
