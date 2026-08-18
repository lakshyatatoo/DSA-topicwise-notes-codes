#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. BETTER — MAP + SORTING
//
// Count frequencies using map.
// Store {frequency, number} pairs.
// Sort by frequency.
//
// Time: O(n log n)
// Space: O(n)
// ============================================================

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> counter;

        for (int n : nums)
        {
            counter[n]++;
        }

        vector<pair<int, int>> arr;

        for (auto &entry : counter)
        {
            arr.push_back({entry.second, entry.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i].second);
        }

        return res;
    }
};

// ============================================================
// 2. HEAP — PRIORITY QUEUE
//
// Keep the k most frequent elements in a min-heap.
// If heap size exceeds k, remove the least frequent element.
//
// Time: O(n log k)
// Space: O(n)
// ============================================================

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counter;

        for (int n : nums)
        {
            counter[n]++;
        }

        // {frequency, number}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        for (auto &entry : counter)
        {
            pq.push({entry.second, entry.first});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> res;

        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

// ============================================================
// 3. OPTIMAL — BUCKET SORT
//
// Group numbers according to their frequency.
//
// freq[i] = numbers occurring i times
//
// Time: O(n) average
// Space: O(n)
// ============================================================

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counter;

        for (int n : nums)
        {
            counter[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for (auto &entry : counter)
        {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;

        for (int i = freq.size() - 1; i >= 0; i--)
        {
            for (int num : freq[i])
            {
                res.push_back(num);

                if (res.size() == k)
                {
                    return res;
                }
            }
        }

        return {};
    }
};