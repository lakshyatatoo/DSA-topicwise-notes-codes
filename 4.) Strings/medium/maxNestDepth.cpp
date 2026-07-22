#include <bits/stdc++.h>
using namespace std;

// brute
int maxDepth(string s)
{
    int cnt = 0;
    int final = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt--;
        final = max(final, cnt);
    }
    return final;
}