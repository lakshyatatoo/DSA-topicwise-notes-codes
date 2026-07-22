#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string postToPre(string s)
    {
        // code here
        stack<string> st;
        int n = s.size();
        int i = n - 1;
        while (i >= 0)
        {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string con = t2 + t1 + s[i];
                st.push(con);
            }
            i--;
        }
        return st.top();
    }
};