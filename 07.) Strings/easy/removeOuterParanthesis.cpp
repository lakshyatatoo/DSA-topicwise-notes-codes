#include <bits/stdc++.h>
using namespace std;

string bruteRemoveOuterParentheses(string s)
{
    vector<string> rem;
    int count = 0;
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            rem.push_back(s.substr(start + 1, i - start - 1));
            start = i + 1;
        }
    }
    string res = "";
    for (string v : rem)
    {
        res += v;
    }
    return res;
}

string betterRemoveOuterParentheses(string s)///stak keep track of outer paranthesis whenever ( mean if stack not empty its ainner and whne ) and after popo stack is not empty its inner paranthesis so store in res
{
    stack<char> st;
    string result = "";

    for (char c : s)
    {
        if (c == '(')
        {
            if (!st.empty())
                result += c;
            st.push(c);
        }
        else
        {
            st.pop();
            if (!st.empty())
                result += c;
        }
    }

    return result;
}



string optimalremoveOuterParentheses(string S) {
    string res;
    int opened = 0;

    for (char c : S) {
        if (c == '(' && opened++ > 0) res += c;
        if (c == ')' && opened-- > 1) res += c;
    }
    return res;
}