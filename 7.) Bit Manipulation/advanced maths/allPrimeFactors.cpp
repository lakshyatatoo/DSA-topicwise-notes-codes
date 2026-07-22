#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    int cnt = 0;
    if (n == 1)
        return false;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
                cnt++;
        }
    }
    return cnt == 2;
}

// 1//brute
// tc: O(n*sqrt(n))
// sc: O(prime factors)

vector<int> priFacAll(int n)
{
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0 && isPrime(i))
            ans.push_back(i);
    }
    return ans;
}

// 2//better//improving above one
// tc= O(sqrt(n)*sqrt(n))=O(n) for large prime nos n
vector<int> priFacAll(int n)
{
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0 && isPrime(i))
        {
            ans.push_back(i);
        }
        if (n / i != i && isPrime(n / i))
        {
            ans.push_back(n / i);
        }
    }
    return ans;
}

// 3/optimal
// tc: O(n)for large prime nos n
vector<int> priFacAll(int n)
{
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    return ans;
}

// 4//optimal improved
// tc= O(sqrt(n)*logn) for large prime nos n
vector<int> priFacAll(int n)
{
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n != 1)
        ans.push_back(n);
    return ans;
}