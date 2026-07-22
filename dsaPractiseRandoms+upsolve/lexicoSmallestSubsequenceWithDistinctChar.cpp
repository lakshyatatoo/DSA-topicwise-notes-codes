#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        stack<char> st;
        map<char, int> mp;
        vector<int> vis(26);
        for (char c : s)
            mp[c]++;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]--;
            if (vis[s[i] - 'a'])
                continue;
            while (!st.empty() && st.top() > s[i])
            {
                if (mp[st.top()] > 0)
                {
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                }
                else
                    break;
            }
            if (!vis[s[i] - 'a'])
            {
                st.push(s[i]);
                vis[s[i] - 'a'] = 1;
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    cin >> s;
    cout << sol.smallestSubsequence(s) << endl; // Output: "abc"
    return 0;
}