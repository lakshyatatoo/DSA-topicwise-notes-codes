// parameterised approach
#include <bits/stdc++.h>
using namespace std;

void factorial(int n, int fact)
{
    if (n < 1)
    {
        cout << fact << endl;
        return;
    }
    factorial(n - 1, fact * n); // fact*n directly
}
int main()
{
    int n;
    cin >> n;
    factorial(n, 1);
}

// functional approach

#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;
}