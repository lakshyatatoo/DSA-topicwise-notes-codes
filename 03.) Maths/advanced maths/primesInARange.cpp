#include <bits/stdc++.h>
using namespace std;

// brute
class Solution
{
public:
    bool checkPrime(int n)
    {
        int cnt = 0;
        for (int i = 1; i * i <= n; i++)
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
    vector<int> primeRange(int l, int r)
    {
        vector<int> ans;
        for (int i = l; i <= r; i++)
        {
            if (checkPrime(i))
                ans.push_back(i);
        }
        return ans;
    }
};

// better
class Solution
{
public:
    vector<int> getSeive(int n)
    {
        vector<int> prime(n + 1, 1);
        prime[0] = prime[1] = 0;
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
        return prime;
    }
    vector<int> primeRange(int l, int r)
    {
        vector<int> ans;
        vector<int> seive = getSeive(r);
        for (int i = l; i <= r; i++)
        {
            if (seive[i])
                ans.push_back(i);
        }
        return ans;
    }
};

// optimal if no of prime till each is asked let say we need to tell no of primes till
// ex- primes between l to r we use prefix sum to calculate no of primes till each index and then we can easily calculate no of primes between l to r by prefix[r] - prefix[l-1]
class Solution
{
public:
    vector<int> getSeive(int n)
    {
        vector<int> prime(n + 1, 1);
        prime[0] = prime[1] = 0;
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
        return prime;
    }
    vector<int> primeRange(int l, int r)
    {
        vector<int> ans;
        vector<int> seive = getSeive(r);
        for (int i = 1; i <= r; i++)
        {
            seive[i] += seive[i - 1];
        }
        int ans = seive[r] - seive[l - 1];
        return ans;
    }
};
