#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]])
        {
            res += mp[s[i + 1]] - mp[s[i]];
            i++;
        }
        else
        {
            res += mp[s[i]];
        }
    }

    return res;
}

// vector is faster
class Solution
{
public:
    string intToRoman(int num)
    {
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string res;

        for (const auto &[value, symbol] : valueSymbols)
        {
            if (num == 0)
                break;

            while (num >= value)
            {
                res += symbol;
                num -= value;
            }
        }

        return res;
    }
};