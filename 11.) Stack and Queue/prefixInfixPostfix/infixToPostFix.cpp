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
    string infixToPostfix(string &s)
    {
        // code here
        stack<char> st;
        int i = 0;
        string ans = "";
        int n = s.size();
        while (i < n)
        {
            if (s[i] <= 'Z' && s[i] >= 'A' || s[i] <= 'z' && s[i] >= 'a' || s[i] <= '9' && s[i] >= '0')
            {
                ans += s[i];
            }
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && ((s[i] != '^' && priority(s[i]) <= priority(st.top())) || (s[i] == '^' && priority(s[i]) < priority(st.top()))))
                { // flip becasue stirng is fliiped too
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
        return ans;
    }
};
