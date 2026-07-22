#include <bits/stdc++.h>
using namespace std;
//brute nested loops but tle on gfg
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int leader=true;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            leader=true;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>arr[i]){
                    leader=false;
                    break;
                }

            }
            if(leader==true){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

//optimal
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int maxi=arr[n-1];
        vector<int> ans;
        ans.push_back(maxi);
        for(int i=n-2;i>=0;i--){

            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                         maxi=arr[i];
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};