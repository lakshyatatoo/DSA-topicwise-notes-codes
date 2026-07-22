#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
void solve()
{
    if (cnt == 11)
    {
        return;
    }

    cout << cnt << " ";

    cnt++;

    solve();
}
int main()
{

    solve();
}

class Solution
{
public:
    int digit = 1;
    void printNos(int n)
    {
        // Code here
        if (digit > n)
        {
            return;
        }
        cout << digit << " ";
        digit++;
        printNos(n);
    }
};