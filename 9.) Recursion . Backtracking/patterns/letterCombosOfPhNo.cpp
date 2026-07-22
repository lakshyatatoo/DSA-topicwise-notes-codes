#include <bits/stdc++.h>
using namespace std;


//recusrion. based on the mapping of digits to characters on a phone keypad
// TC: O(4^n) where n is the length of the input digits string, since each digit can map to at most 4 characters (like '7' and '9').
// SC: O(n) for the recursion stack, where n is the length of the input
//direct is also good
class Solution
{
public:
    void solve(int index, string &digits, string &res, vector<string> &mapping, vector<string> &ans)
    {
        if (index == digits.size())
        {
            ans.push_back(res);
            return;
        }

        int x = digits[index] - '2'; // convert char to index (0-7)

        for (char ch : mapping[x])
        {
            res.push_back(ch);
            solve(index + 1, digits, res, mapping,ans);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> ans;
        vector<string> mapping = {
            "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"};

        string res = "";
        solve(0, digits, res, mapping,ans);

        return ans;
    }
};