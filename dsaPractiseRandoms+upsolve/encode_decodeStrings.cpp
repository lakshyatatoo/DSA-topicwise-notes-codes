#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string encode(vector<string> &arr)
    {
        // write your logic to encode the strings
        string s = "";
        for (string x : arr)
        {
            s += to_string(x.size()) + "/" + x;
        }
        return s;
    }

    vector<string> decode(string &s)
    {
        // write your logic to decode the string
        vector<string> we;
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int j=i;
            while(s[j] != '/')
                j++;
            string lenStr=s.substr(i,j-i);
            int len=stoi(lenStr);
            i=j+1;
            we.push_back(s.substr(i, len));
            i+=len;
        }
        return we;
    }
};

  