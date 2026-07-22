#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToInfix(string &exp)
    {
        int i = 0;
        stack<string> st;
        int n = exp.size();
        while (i < n)
        {
            if (exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= '0' && exp[i] <= '9')
            {
                st.push(string(1, exp[i]));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string con = "(" + t2 + exp[i] + t1 + ")";
                st.push(con);
            }
            i++;
        }
        return st.top();
    }
};
