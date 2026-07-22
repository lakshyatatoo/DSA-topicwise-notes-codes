#include <bits/stdc++.h>
using namespace std;

// binary search
// data structure isa map whcih has a key and then value is a vector of pair of value and timestamp
// tc: O(logn) for get and O(1) for set
class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> mp; // initialised when we call timemap constructor
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";
        string ans = "";
        vector<pair<string, int>> &values = mp[key]; // reference instead od storing in another vector
        int low = 0, high = values.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (values[mid].second <= timestamp)
            {
                ans = values[mid].first;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};