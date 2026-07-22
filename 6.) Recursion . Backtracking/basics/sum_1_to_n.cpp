// parameterised
class solution
{
public:
    int sumOfSeries(int n, int sum = 0)
    {
        if (n == 0)
        {
            return sum;
        }
        return sumOfSeries(n - 1, sum + n);
    }
};

// functional
class Solution
{
public:
    int sumOfSeries(int n)
    {
        if (n == 0)
            return 0;
        return n + sumOfSeries(n - 1);
    }
};

// or sum of individual digtis of n would look like n+sos(n-1);