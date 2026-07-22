// // general approach
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string s;
//     cin >> s;
//     int r = s.length() - 1;
//     int l = 0;
//     bool py = true;
//     while (l > r)
//     {
//         if (s[l] != s[r])
//         {
//             py = false;
//             break;
//         }
//         l++;
//     }

//     if (py)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;
// }

// recursive approach(functional approach)
#include <bits/stdc++.h>
using namespace std;
bool palindrome(string &s, int i)
{
    if (s[i] != s[s.size() - i - 1])
        return false;
    if (i >= s.size() / 2)
        return true;
    return palindrome(s, i + 1);
}

int main()
{
    string s;
    cin >> s;

    bool ans = palindrome(s, 0);
    cout << boolalpha << ans << endl;
}