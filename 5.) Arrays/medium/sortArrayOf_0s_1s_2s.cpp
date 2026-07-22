#include <bits/stdc++.h>
using namespace std;
//brute simple sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

//better using cnt
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n=nums.size();
       int cnt0=0;
       int cnt1=0;
       int cnt2=0;
       for(int i=0;i<n;i++){
        if(nums[i]==0) cnt0++;
        else if(nums[i]==1) cnt1++;
        else cnt2++;
       }
       for(int i=0;i<cnt0;i++){
        nums[i]=0;
       }
        for(int i=cnt0;i<cnt1+cnt0;i++){
        nums[i]=1;
       }
        for(int i=cnt0+cnt1;i<cnt2+cnt1+cnt0;i++){
        nums[i]=2;
       }

    }
};

//optimal dutch national flag algo ?binary?
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};