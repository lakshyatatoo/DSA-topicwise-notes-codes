// // basic store and fetch or a freq of element using hash array
// #include <bits/stdc++.h>
// using namespace std;
// int hshh[10000000]; // declaring a global hash array of 10^7
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     int hsh[1000000];//declaring local array inside main of amx 10^6.
//     //so we can store values till 10^6 or ^7 in hash map
//     int hash[n + 1] = {0}; // all elements 0
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         hash[arr[i]]++;
//     }
//     // precompute and store values in hash array

// int q; // queries for element
// cin >> q;
// while (q--)
// {
//     int a;
//     cin >> a;

//     cout << hash[a] << endl;
// }
// }

// character hashing
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     int hash[26] = {0}; // hash of 256 canbe done if dont want to input using -'a'

//     for (int i = 0; i < s.size(); i++)
//     {
//         hash[s[i] - 'a']++;
//     }
//     // for (auto x : hash)
//     // {

//     //     cout << x << " ";
//     // }
//     int q; // queries for element
//     cin >> q;
//     while (q--)
//     {
//         char y;
//         cin >> y;

//         cout << hash[y - 'a'] << endl;//diret of hash y can be taken
//     }
//     cout << endl;
// }

// big numbers hashing using map and unordered map
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    unordered_map<int, int> mp; // map will store in a sorted way
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int y;
    //     cin >> y;

    //     cout << mp[y] << endl;
    // }
    // cout << endl;
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl; // stores in sorted manner.
        // unordered map stores in order randomised
    }
}