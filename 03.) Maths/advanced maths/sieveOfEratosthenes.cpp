#include <bits/stdc++.h>
using namespace std;

// brute
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
int countPrimes(int n)
{
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
            cnt++;
    }
    return cnt;
}

// better
int countPrimes(int n)
{
    vector<int> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            cnt++;
    }
    return cnt;
}

// optimal
int countPrimes(int n)
{
    vector<int> prime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            cnt++;
    }
    return cnt;
}