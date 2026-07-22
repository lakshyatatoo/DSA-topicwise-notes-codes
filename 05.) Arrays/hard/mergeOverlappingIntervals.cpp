#include <bits/stdc++.h>
using namespace std;

// // brute
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (ans.size() != 0 && end <= ans.back()[1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] <= end)
                {
                    end = max(end, intervals[j][1]);
                }
                else
                {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};

// optimal
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            if (ans.size() == 0 || intervals[i][0] > ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);                           
            }
        }
        return ans;
    }
};

//optimal too 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (e >= intervals[i][0]) {
                e = max(e, intervals[i][1]);
            } else {
                ans.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};
//tc: O(nlogn) + O(n) ~ O(nlogn)
//sc: O(n) for sorting + O(n) for ans ~ O(n)