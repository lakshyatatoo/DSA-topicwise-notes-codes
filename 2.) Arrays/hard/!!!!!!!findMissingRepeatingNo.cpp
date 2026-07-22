#include <bits/stdc++.h>
using namespace std;

// brute
// runnning 2 loops tle
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        int missing = -1;
        int repeating = -1;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == i)
                {
                    cnt++;
                }
            }
            if (cnt == 0)
            {
                missing = i;
            }
            else if (cnt == 2)
            {
                repeating = i;
            }
            if (missing != -1 && repeating != -1)
            {
                break;
            }
        }

        return {repeating, missing};
    }
};

// // better hashing
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        int missing = -1;
        int repeating = -1;
        vector<int> hsh(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            hsh[arr[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (hsh[i] == 0)
            {
                missing = i;
            }
            else if (hsh[i] == 2)
            {
                repeating = i;
            }
            if (missing != -1 && repeating != -1)
            {
                break;
            }
        }

        return {repeating, missing};
    }
};

// // optimal (maths)

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        long long s = 0, s2 = 0;
        long long sn = (long long)n * (n + 1) / 2;
        long long s2n = (long long)n * (n + 1) * (2 * n + 1) / 6;
        for (int i = 0; i < n; i++)
        {
            s += arr[i];
            s2 += (long long)arr[i] * arr[i];
        }
        long long val1 = s - sn;
        long long val2 = s2 - s2n;
        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};

// // optimal (xor approach)

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }
        int bitno = 0;
        // bitno=xr&~(xr-1);//to find the set no which is different for both these. no in xr so
        // we can seperate them.
        while (1)
        {
            if ((xr & (1 << bitno)) != 0) // bca != has higher precedence than &
            {                             // not equal to zero becasw only  1 will be when both are same 1 1 that is set bit of xr's result
                break;
            }
            bitno++;
        }
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) // for array elements
        {
            if ((arr[i] & (1 << bitno)) != 0)
            { // bcz //(1<<bitno) - Creates a mask with only the bitno-th bit set
                // bitno = 2: (1<<2) = 100₂ = 4
                //  bitno = 1: (1<<1) = 010₂ = 2
                //  bitno = 0: (1<<0) = 001₂ = 1
                one = one ^ arr[i];
            }
            else
            {
                zero = zero ^ arr[i];
            }
        }
        for (int i = 1; i <= n; i++)
        { // for n elements
            if ((i & (1 << bitno)) != 0)
            {
                one = one ^ i;
            }
            else
            {
                zero = zero ^ i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == zero)
                cnt++;
        }
        if (cnt == 2)
            return {zero, one};
        else
            return {one, zero};
    }
};
