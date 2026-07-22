#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int ones = 0;
        for (char c : s)
        {
            if (c == '1')
                ones++;
        }
        int ans = ones, n = s.size(), i = 0, cfz = 0, c11 = 0, csz = 0;
        while (i < n && s[i] == '1')
            i++;
        while (i < n && s[i] == '0')
            i++, cfz++;
        while (i < n)
        {
            c11 = 0;
            while (i < n && s[i] == '1')
                c11++, i++;
            if (c11 == 0)
                break;
            csz = 0;
            while (i < n && s[i] == '0')
                csz++, i++;
            if (csz == 0)
                break;
            ans = max(ans, ones + cfz + csz);
            cfz = csz;
        }
        return ans;
    }
};