#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int priority(char ch)
    {
        if (ch == '^')
            return 3;
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }
    void reverse(string &s)
    {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            swap(s[l], s[r]);
            if (s[l] == '(')
                s[l] = ')';
            else if (s[l] == ')')
                s[l] = '(';

            if (l != r)
            {
                if (s[r] == '(')
                    s[r] = ')';
                else if (s[r] == ')')
                    s[r] = '(';
            }
            l++;
            r--;
        }
    }
    string infixToPrefix(string &s)
    {
        int n = s.size();
        reverse(s);
        int i = 0;
        stack<char> st;
        string ans = "";
        while (i < n)
        {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
            {
                ans += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && ((s[i] != '^' && priority(s[i]) < priority(st.top())) || (s[i] == '^' && priority(s[i]) <= priority(st.top()))))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans);
        return ans;
    }
};
