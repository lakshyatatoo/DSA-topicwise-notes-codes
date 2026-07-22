// printing n fibonacci nos after 0 and 1;
// general approach
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int sum = 0;
    int n;
    cin >> n;
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for (int i = 1; i <= n; i++)
    {
        sum = fib[i - 1] + fib[i];

        fib.push_back(sum);
    }
    for (auto no : fib)
    {
        cout << no << " ";
    }
    cout << endl;
}

// recursive approach
#include <bits/stdc++.h>
using namespace std;
void fib(vector<int> &a, int i, int n) // updation on original so no out of bound access
{
    if (i > n)
        return;

    cout << a[i] + a[i - 1] << " ";

    fib(a, i + 1, n);
}
int main()
{
    int n;
    cin >> n; // will print n fibonacci nos after 0 and 1
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    cout<<0<<" "<<1<<" ";

    fib(a, 1, n);
}

// recursive approach multiple recursion calls
//  fibonacci value of nth element
#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if (n <= 1)
        return n;

    int last = fib(n - 1);
    int slast = fib(n - 2);

    return last + slast;
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
}