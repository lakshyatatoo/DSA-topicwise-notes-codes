#include <bits/stdc++.h>
using namespace std;

int recursiveAtoi(string s, int i, int sign, int result)
{
    if (i == s.size())
        return sign * result;
    if (s[i] < '0' || s[i] > '9')
        return sign * result;
    int digit = s[i] - '0';
    if (result > (INT_MAX - digit) / 10)
    {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }

    result = result * 10 + digit;
    return recursiveAtoi(s, i + 1, sign, result);
}
int myAtoi(string s)
{
    int i = 0, sign = 1;

    while (s[i] == ' ')
    {
        i++;
    }
    if (s[i] == '-' || s[i] == '+')
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    return recursiveAtoi(s, i, sign, 0);
}