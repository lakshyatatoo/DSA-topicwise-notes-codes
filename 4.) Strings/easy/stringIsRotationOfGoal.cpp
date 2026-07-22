#include <bits/stdc++.h>
using namespace std;

// brute
void rotateWordByUnit(string &s)
{
    int n = s.size();
    reverse(s.begin(), s.end());
    int target = n - 1;
    reverse(s.begin(), s.begin() + target);
}
bool rotateString(string s, string goal)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s == goal)
        {
            return true;
        }
        rotateWordByUnit(s);
    }
    return false;
}

// optimal
bool rotateString(string s, string goal)
{
    string res = s + s;
    return res.find(goal) != string::npos && s.size() == goal.size();
}