#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    string res = "";
    int i= num.size() - 1;
    while(i>=0)
    {
        if ((num[i] - '0' )% 2 != 0)
        {
            res = num.substr(0, i + 1);
            break;
        }
        i--;
    }
    return res;
}