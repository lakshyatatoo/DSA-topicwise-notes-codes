#include <bits/stdc++.h>
using namespace std;

// brute good fro gfg but tle on leetcdoe
// will work perfectly fine in interviews
class Solution
{
public:
    vector<vector<string>> findSequences(vector<string> &words, string &s, string &e)
    {
        vector<vector<string>> ans;
        unordered_set<string> st(words.begin(), words.end());
        queue<vector<string>> q;
        q.push({s});
        vector<string> used;
        used.push_back(s);
        int lvl = 0;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            if (vec.size() > lvl)
            {
                lvl++;
                for (auto it : used)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();
            if (word == e)
            {
                if (ans.size() == 0)
                    ans.push_back(vec);
                else if (ans[0].size() == vec.size())
                    ans.push_back(vec);
            }
            for (int i = 0; i < word.size(); i++)
            {
                char og = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = og;
            }
        }
        return ans;
    }
};