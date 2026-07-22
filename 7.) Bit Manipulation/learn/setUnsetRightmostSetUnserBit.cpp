#include <bits/stdc++.h>
using namespace std;

int unsetRightmostSetBit(int n)
{
    return n & (n - 1);
}
int setRightmostUnsetBit(int n)
{
    return n | (n + 1);
}