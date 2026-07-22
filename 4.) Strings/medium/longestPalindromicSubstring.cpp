#include <bits/stdc++.h>
using namespace std;

//brute
bool isPalindrome(string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
string longestPalindrome(string s)
{
    int n = s.size();
    int mL = 1;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                int x=j-i+1;
                mL = max(mL, x);
                if (mL == x)
                {
                    start = i;
                }
            }
        }
    }
    return s.substr(start, mL);
}



//optimal
int expandAC(string s,int left,int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}
string longestPalindrome(string s){
    if(s.empty())return "";
    int n=s.size();
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        int even=expandAC(s,i,i);
        int odd=expandAC(s,i,i+1);
        int maxLen=max(even,odd);
        if(maxLen>end-start){
            start=i-(maxLen-1)/2;
            end=i+maxLen/2;
        }
    }
    return s.substr(start,end-start+1);
}