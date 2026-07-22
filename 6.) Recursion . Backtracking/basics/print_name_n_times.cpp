#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
void show(int n)
{
    if (cnt > n)
    {
        return; // base case
    }
    cout << "GFG" << " ";
    cnt++;
    show(n);
}
int main()
{
    int n;
    cin >> n;
    show(n);
}