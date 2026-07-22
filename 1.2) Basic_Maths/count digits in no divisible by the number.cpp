class Solution
{
public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n)
    {
        // code here
        int x = n;
        int ans = 0;
        while (x > 0)
        {

            int d = x % 10;
            if (d != 0)
            {
                if (n % d == 0)
                {
                    ans++;
                }
            }
            x = x / 10;
        }
        return ans;
    }
};