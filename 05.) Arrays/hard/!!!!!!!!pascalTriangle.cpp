#include <bits/stdc++.h>
using namespace std;
// 1.) finding a element in pascal triangle
// brute direct formula/////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
int pascalelement(int n, int r)
{
    int fact1 = 1;
    for (int i = 1; i <= n; i++)
    {
        fact1 *= i;
    }
    int fact2 = 1;
    for (int i = 1; i <= r; i++)
    {
        fact2 *= i;
    }
    int fact3 = 1;
    for (int i = 1; i <= n - r; i++)
    {
        fact3 *= i;
    }
    return fact1 / (fact2 * fact3);
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << pascalelement(n - 1, r - 1);
    return 0;
}

// better//////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
int pascalelement(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }

    return ans;
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << pascalelement(n - 1, r - 1);
    return 0;
}

// 2.) generating pascal ith row
// brute///////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
int pascalelement(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << pascalelement(n - 1, i - 1) << " ";
    }

    return 0;
}

// optimal///////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
}

// 3.) printing pascal triangle
// brute///////////////////////////////////////////////////////////
    class Solution
{
public:
    int pascalelement(int n, int r)
    {
        int ans = 1;
        for (int i = 0; i < r; i++)
        {
            ans = ans * (n - i);
            ans = ans / (i + 1);
        }

        return ans;
    }
    vector<vector<int>> generate(int n)
    {

        vector<vector<int>> anss;
        ;

        for (int row = 1; row <= n; row++)
        {
            vector<int> temp;
            for (int col = 1; col <= row; col++)
            {
                temp.push_back(pascalelement(row - 1, col - 1));
            }
            anss.push_back(temp);
        }
        return anss;
    }
};

// optimal////////////////////////////////////////////////////////////
class Solution
{
public:
    vector<int> generaterow(int row)
    {
        vector<int> ansrow;
        long long ans = 1;
        ansrow.push_back(1);
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / (col);
            ansrow.push_back(ans);
        }

        return ansrow;
    }
    vector<vector<int>> generate(int n)
    {

        vector<vector<int>> anss;
        for (int row = 1; row <= n; row++)
        {
            anss.push_back(generaterow(row));
        }
        return anss;
    }
};