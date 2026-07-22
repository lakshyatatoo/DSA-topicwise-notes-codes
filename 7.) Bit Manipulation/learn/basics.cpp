#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert2Binary(int n)
    {
        string s = "";
        while (n != 1)
        {
            if (n % 2 == 1)
                s += '1';
            else
                s += '0';
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int convert2Decimal(string s)
    {
        int len = s.size();
        int power2 = 1;
        int nums = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                nums += power2;
              
            }
              power2 *= 2;
        }
        return nums;
    }

    int setKthBit(int n, int k)
    {
        return (n | (1 << k));
    }

    int clearKthBit(int &n, int k)
    {
        return n & ~(1 << k);
    }
    int toggleKthBit(int &n, int k)
    {
        return n ^ (1 << k);
    }
};
