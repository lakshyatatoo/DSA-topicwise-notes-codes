// brute
//  run a loop from 1 to n and check if cnt of divisors is 2 or not
//  if return true else return false

// optimal
//  tc=O(sqrt(n)) sc=O(1)
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
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
        if (cnt == 2)
            return true;
        else
            return false;
    }
};
