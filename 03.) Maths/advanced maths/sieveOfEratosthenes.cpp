#include <bits/stdc++.h>
using namespace std;

// brute
// simple check for 2 to n-1 if prime or not
// tc = O(n*sqrt(n))
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
// sieve of eratosthenes
// assuming each number is a prime then from 2 / each prime mark all composite multiples as 0 asn traverse and print
// tc = O(n*log(log(n)))
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
// further optimisation allow us
// what it means is that we can startfrom ii as all multiples of i less than ii would be been
// ex let say i is x then till 2 to x other prev primes cover xi and remaing are just factors/multiples of smaller primes so we can start from i*i as all multiples of i less than i*i would have been marked by smaller primes
// tc = O(n*log(log(n)))
// sc = O(n)
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