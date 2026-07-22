// a better approach will be just decremnt from min(a,b) to i-- so we break at gcd
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> lcmAndGcd(int a, int b)
    {

        vector<int> gclc(2);

        // gcd
        int c = min(a, b);
        int gc = 1;
        for (int i = c; i > 0; i--)
        { // instead of increasing we can do just decrement and break loop
            if (a % i == 0 && b % i == 0)
            {
                gc = i;
                break;
                // will return geecd if if condition satisfies
            }
        }
        gclc[1] = gc;

        // lcm
        int lc = (a * b) / gc;
        gclc[0] = lc;

        return gclc;
    }
};
