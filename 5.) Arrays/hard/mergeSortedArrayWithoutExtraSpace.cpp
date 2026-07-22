#include <bits/stdc++.h>
using namespace std;

// brute
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> a3(n + m);
        int left = 0, right = 0, index = 0;
        // merge
        while (left < n && right < m) {
            if (nums1[left] <= nums2[right]) {
                a3[index++] = nums1[left++];
            } else {
                a3[index++] = nums2[right++];
            }
        }
        while (left < n) {
            a3[index++] = nums1[left++];
        }
        while (right < m) {
            a3[index++] = nums2[right++];
        }
        // return
        for (int i = 0; i < n + m; i++) {
            if (i < n) {
                nums1[i] = a3[i];
            } else {
                nums2[i-n] = a3[i];
            }
        }
    }
};

// //optimal 1
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int left=n-1;
        int right=0;
        while(left>=0 && right<m){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--,right++;
            }
            else {
                break;
            }
        }
        for(int i=n;i<n+m;i++){
            nums1[i]=nums2[i-n];
        }
        sort(nums1.begin(),nums1.end());

    }
};

// optimal 2
class Solution {
private:
    void swapp(vector<int>& nums1, vector<int>& nums2, int left, int right) {
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
        }
    }

public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {

        int len = n + m;
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                if (left < n && right >= n) {
                    swapp(nums1, nums2, left, right - n);
                } else if (left >= n) {
                    swapp(nums2, nums2, left - n, right - n);
                } else {
                    swapp(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
        for (int i = n; i < n + m; i++) {
            nums1[i] = nums2[i - n];
        }
    }
};