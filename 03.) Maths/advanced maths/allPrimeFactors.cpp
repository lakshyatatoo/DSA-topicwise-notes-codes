#include <bits/stdc++.h>
using namespace std;

// Prime Check
// Time Complexity: O(sqrt(n)) Space Complexity: O(1)

bool isPrime(int n)
{
    if (n == 1)
        return false;

    int cnt = 0;

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

// 1. Brute Force
// Finds all distinct prime factors of n.
// Idea: Check every number from 2 to n. If it divides n and is prime, store it.
// Time Complexity: O(n * sqrt(n)) Space Complexity: O(number of prime factors)

vector<int> primeFactorsBrute(int n)
{
    vector<int> ans;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0 && isPrime(i))
            ans.push_back(i);
    }

    return ans;
}

// 2. Better
// Uses the factor pair property.
// If i is a factor of n,then n / i is also a factor. Therefore, we only iterate till sqrt(n).
// Time Complexity: O(sqrt(n) * sqrt(n)) Space Complexity: O(number of prime factors)

vector<int> primeFactorsBetter(int n)
{
    vector<int> ans;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0 && isPrime(i))
            ans.push_back(i);

        if (n % i == 0 &&
            n / i != i &&
            isPrime(n / i))
        {
            ans.push_back(n / i);
        }
    }

    return ans;
}

// Prime Factorisation Based Approaches

//
// The following approaches do NOT explicitly check
// whether a factor is prime.
//
// Reason:
// Every composite number is made up of smaller
// prime factors.
//
// Since all occurrences of a factor are removed
// immediately, any composite number automatically
// loses the prime factors required to divide n.
//
// Therefore, whenever a new divisor is found,
// it is guaranteed to be prime.

// ==================================================
// 3. Optimal
// ==================================================
// Distinct Prime Factors using Prime Factorisation
//
// Example:
// 60 = 2² × 3 × 5
//
// 60 -> 15 (remove all 2s)
// 15 -> 5  (remove all 3s)
// 5  -> 1  (remove all 5s)
//
// Answer: {2, 3, 5}
//
// Time Complexity: O(n) in worst case
// (when n itself is prime)
//
// Space Complexity: O(number of prime factors)

vector<int> primeFactorsOptimal(int n)
{
    vector<int> ans;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            while (n % i == 0)
                n /= i;
        }
    }

    return ans;
}

// ==================================================
// 4. Optimal Improved
// ==================================================
//
// As factors are continuously removed,
// n becomes smaller after every division.
//
// Therefore, checking till sqrt(n) is sufficient.
//
// If any value greater than 1 remains after the loop,
// it must be prime.
//
// Why?
//
// Any composite number must have at least one factor
// less than or equal to its square root.
//
// If such a factor existed, it would already have
// been discovered and removed.
//
// Hence the remaining n can only be:
//
// 1  -> all factors removed
// prime -> last remaining prime factor
//
// Time Complexity: O(sqrt(n) * log n)
// Commonly considered O(sqrt(n))
//
// Space Complexity: O(number of prime factors)

vector<int> primeFactorsOptimalImproved(int n)
{
    vector<int> ans;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            while (n % i == 0)
                n /= i;
        }
    }

    // Remaining value is prime
    if (n != 1)
        ans.push_back(n);

    return ans;
}
