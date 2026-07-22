// if the divisors are not exactly 1 number and 1 else false
class Solution
{
public:
    bool isPrime(int n)
    {

        int cnt = 0;
        if (n == 1)
            return false;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt++;
                if (n / i != i)
                {
                    cnt++;
                }
            }
        }

        if (cnt != 2)
            return false;
        else
            return true;
    }
};
