#include <bits/stdc++.h>
using namespace std;

// brute
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// optimal
bool isAnagram(string s, string t)
{
    unordered_map<char, int> charCount;
    if (s.size() != t.size())
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        charCount[s[i]]++;
        charCount[t[i]]--;
    }
    for (auto &pair : charCount)
    {
        if (pair.second != 0)
        {
            return false;
        }
    }
    return true;
}
