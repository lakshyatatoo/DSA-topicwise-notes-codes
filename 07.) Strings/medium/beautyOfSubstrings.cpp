#include <bits/stdc++.h>
using namespace std;

// brute
int indiBeauty(int i, int j, string s)
{
    vector<int> arr(26, 0);

    for (int x = i; x <= j; x++)
    {
        arr[s[x] - 'a']++;
    }

    int maxi = 0;
    int mini = INT_MAX;

    for (int freq : arr)
    {

        if (freq > 0)
        {
            maxi = max(maxi, freq);
            mini = min(mini, freq);
        }
    }

    return maxi - mini;
}
int beautySum(string s)
{
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            total = total + indiBeauty(i, j, s);
        }
    }
    return total;
}

// optimal
class Solution
{
public:
    int beautySum(string s)
    {
        int total = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> arr(26, 0);
            for (int j = i; j < s.size(); j++)
            {
                arr[s[j] - 'a']++;
                int maxi = 0;
                int mini = INT_MAX;
                for (int freq : arr)
                {
                    if (freq > 0)
                    {
                        maxi = max(maxi, freq);
                        mini = min(mini, freq);
                    }
                }
                total = total + maxi - mini;
            }
        }
        return total;
    }
};