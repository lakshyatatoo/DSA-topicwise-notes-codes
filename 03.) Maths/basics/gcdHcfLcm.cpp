#include <bits/stdc++.h>
using namespace std;

// brute force approach
// or we can just decremnt from min(a,b) to i-- so we break at gcd
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

// optimlal for hcf and lcm
// eucledian
// tc: o(log(min(a,b)))
int main()
{
    int a, b;
    cin >> a >> b;

    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (b == 0)
    {
        cout << a << endl;
    }
    else
    {
        cout << b << endl;
    }
}
