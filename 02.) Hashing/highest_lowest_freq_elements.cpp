// vector<int> getFrequencies(vector<int> &v)
// {

//     unordered_map<int, int> mp;

//     for (auto x : v)
//     {
//         mp[x]++;
//     }
//     int mini = INT_MAX;
//     int maxi = 0;
//     int mife = INT_MAX;
//     int mafe = INT_MAX;
//     for (auto it : mp)

//     {
//         if (it.second > maxi || (it.second == maxi && it.first < mafe))
//         {
//             mafe = it.first;
//             maxi = it.second;
//         }

//         if (it.second < mini || (it.second == mini && it.first < mife))
//         {
//             mife = it.first;
//             mini = it.second;
//         }
//     }
//     vector<int> ans;
//     ans.push_back(mafe);
//     ans.push_back(mife);
//     return ans;
// }