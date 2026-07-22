#include <bits/stdc++.h>
using namespace std;

// optimal
bool isIsomorphic(string s, string t)
{

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int i = 0; i < s.size(); i++)
    {

        if (mp1.find(s[i]) != mp1.end())
        {
            if (mp1[s[i]] != t[i])
                return false;
        }
        if (mp2.find(t[i]) != mp2.end())
        {
            if (mp2[t[i]] != s[i])
                return false;
        }

        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }

    return true;
}

// brute(because of nested check if may become nxk(which no of pair checked can be n and in worst case k can be n))
bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> charMap;

    for (int i = 0; i < s.length(); ++i)
    {
        char sc = s[i];
        char tc = t[i];

        if (charMap.count(sc))
        {
            if (charMap[sc] != tc)
            {
                return false;
            }
        }
        else
        {
            for (auto &pair : charMap)
            {
                if (pair.second == tc)
                {
                    return false;
                }
            }
            charMap[sc] = tc;//if not paired anywhere get the mapping and store in map
        }
    }

    return true;
}