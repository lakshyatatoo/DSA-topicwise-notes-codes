#include <bits/stdc++.h>
using namespace std;

//
// ==========================================================
// BRUTE FORCE APPROACH
// TC: O(sqrt(N)) per query
// ==========================================================
//

vector<int> primeFactorisation(int n)
{
    vector<int> ans;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                ans.push_back(i);
                n /= i;
            }
        }
    }

    // Remaining prime factor
    if (n != 1)
        ans.push_back(n);

    return ans;
}

vector<vector<int>> findPrimeFactors(vector<int> queries)
{
    vector<vector<int>> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        ans.push_back(primeFactorisation(queries[i]));
    }

    return ans;
}

//
// ==========================================================
// OPTIMAL APPROACH USING SPF (Smallest Prime Factor)
// Preprocessing: O(N log log N)
// Factorisation: O(log N)
// ==========================================================
//

vector<vector<int>> findPrimeFactors(vector<int> queries)
{
    // SPF array
    vector<int> spf(1e5 + 1);

    for (int i = 2; i <= 1e5; i++)
    {
        spf[i] = i;
    }

    // Sieve for SPF
    for (int i = 2; i * i <= 1e5; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= 1e5; j += i)
            {
                if (spf[j] == j) // not marked yet
                {
                    spf[j] = i;
                }
            }
        }
    }

    vector<vector<int>> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        int n = queries[i];
        vector<int> temp;

        while (n != 1)
        {
            temp.push_back(spf[n]);
            n /= spf[n];
        }

        ans.push_back(temp);
    }

    return ans;
}

//
// ==========================================================
// GFG STYLE SOLUTION
// Using SPF + Sieve
// ==========================================================
//

class Solution
{
public:
    void sieve(int n, vector<int> &ans)
    {
    }

    vector<int> findPrimeFactors(int N)
    {
        vector<int> ans;

        // Smallest Prime Factor array
        vector<int> spf(1e5 + 1);

        for (int i = 2; i <= 1e5; i++)
        {
            spf[i] = i;
        }

        // Build SPF using sieve
        for (int i = 2; i * i <= 1e5; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j <= 1e5; j += i)
                {
                    if (spf[j] == j) // not marked yet
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        // Extract prime factors
        while (N != 1)
        {
            ans.push_back(spf[N]);
            N /= spf[N];
        }

        return ans;
    }
};