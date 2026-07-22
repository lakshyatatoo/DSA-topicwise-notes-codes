#include <bits/stdc++.h>
using namespace std;

// Q1........ To reach the top, how many steps can be skipped?
//  only for single skip multiple skip is a dp          Given a starting point i and a top point n
//            how many ways can we reach top n if at most we can skip by one step?
//            Normal movement is one step at a time.
//            input - n,i,x;
// int main()
// {
//     int n, i, x;
//     cin >> n >> i >> x;
//     int cnt = 0;
//     for (int j = i; j <= n; j++)
//         if (j + x <= n)
//             cnt++;
//     cnt++;
//     cout << cnt;
// }

// Q2........ An event management company come with unique idea.
//            Given the string of ticket remove e f g occurence from it.
// int main()
// {
//     string x;
//     cin >> x;
//     x.erase(remove_if(x.begin(), x.end(), [](char c) { return c == 'E' || c == 'F' || c == 'G'; }), x.end());
//     cout << x;
// }

// Q3........ new way to sort a string . takes all unique char from string and sort in that order apple like eapl
//
// if we remove all occurence and only consider first occurence then in that order
// we need to use unoredered_set
// int main()
// {
//     string x;
//     cin >> x;
//     char lc = x[x.length() - 1];
//     while (!x.empty() && x.back() == lc)
//         x.pop_back();
//     string y;
//     y += lc;
//     unordered_set<char> s;
//     for (char c : x)//if order must be preserved and contigous ar ealso not allowed
//     {
//         if (!s.count(c))
//         {
//             y += c;
//             s.insert(c);
//         }
//     }

//     cout << y;
// }

// Q4........ given array numbre from 1-10 one number is missing and need to find the missing number
// or we can do another simpe apporach of numsum vs ovrsum
// int main()
// {
//     // vector<int> vis(11, 0);
//     // for (int i = 0; i < 9; i++)
//     // {
//     //     int x;
//     //     cin >> x;
//     //     vis[x] = 1;
//     // }
//     // for (int i = 1; i <= 10; i++)
//     // {
//     //     if (!vis[i])
//     //     {
//     //         cout << i;
//     //         break;
//     //     }
//     // }
//     // sum problem
//     // int numSum = 0, ovrSum = 0;
//     // for (int i = 0; i < 9; i++)
//     // {
//     //     int x;
//     //     cin >> x;
//     //     numSum += x;
//     // }
//     // ovrSum = 10 * (10 + 1) / 2;
//     // cout << ovrSum - numSum << endl;
//     // xor way
//     // int xr = 0;
//     // for (int i = 1; i <= 10;i++)
//     // {
//     //     xr ^= i;
//     // }
//     // for (int i = 0; i < 9; i++)
//     // {
//     //     int x;
//     //     cin >> x;
//     //     xr ^= x;
//     // }
//     // cout << xr << endl;
// }

// Q5........ planning a pcnic and love maths a group of friends
int main()
{
}
