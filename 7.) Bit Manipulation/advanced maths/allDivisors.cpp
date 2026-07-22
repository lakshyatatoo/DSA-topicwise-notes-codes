#include <bits/stdc++.h>
using namespace std;

// brute
vector<int> allDivs(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            ans.push_back(i);
    }
    return ans;
}

// optimal
vector<int> allDivs(int n)
{
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if ((n / i != i))
            {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}