#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }

    vector<pair<char, int>> storer(mp.begin(), mp.end());
    sort(storer.begin(), storer.end(), [](auto &p1, auto &p2)
         {
             return p1.second > p2.second; // descending order
         });

    string res="";
    for(auto &p:storer)
    {
        for(int i=0;i<p.second;i++)
        {
            res+=p.first;
        }
    }
    return res;
}


//optimal
string frequencySort(string s){
    int n=s.size();
    vector<int> freq(256,0);
    for(char c:s){
        freq[c]++;
    }
    vector<vector<char>> bucket(n+1);
    for(int i=0;i<256;i++){
        if(freq[i]>0){
            bucket[freq[i]].push_back((char)i);
        }
    }
    string res="";
    for(int i=n;i>=1;i--){
        for(char c:bucket[i]){
            res.append(i,c);
        }
    }
    return res;
}