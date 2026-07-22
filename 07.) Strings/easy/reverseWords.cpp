#include <bits/stdc++.h>
using namespace std;

// brute
string reverseWords(string s)
{
    vector<string> words;
    string word = "";
    for (char c : s)
    {
        if (c != ' ')
        {
            word += c;
        }
        else
        {
            if (!word.empty())
            {
                words.push_back(word);
                word = "";
            }
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string res = "";
    for (int i = 0; i < words.size(); i++)
    {
        res += words[i];

        if (i != words.size() - 1)
        {
            res += " ";
        }
    }
    return res;
}

// better
string reverseWords(string s)
{
    int i = s.size() - 1;
    int j = 0;
    string res = "";
    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
            i--;
        if (i < 0)
            break;
        j = i;
        while (j >= 0 && s[j] != ' ')
            j--;
        res += s.substr(j + 1, i - j);
        if (!res.empty())
            res += " ";

        i = j - 1;
    }
    if (!res.empty())
        res.pop_back();
    return res;
}

// optimal
string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && s[i] != ' ')
        {
            s[right++] = s[i++];
        }
        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
    }
    if (right > 0)
        s.resize(right - 1);
    return s;
}
