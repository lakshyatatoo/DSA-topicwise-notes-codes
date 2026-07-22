#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        while(n>0){
            int digit=n%10;
            mp[digit]++;
            n=n/10;
        }
        long long sum=0;
        for(auto it:mp){
            sum=sum+(it.first*it.second);
        }
        return sum;
    }
};