// Link:https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Time Complexity: O(N)
// Sapce Complexity: O(1)

class Solution
{
public
    int cntBits(int n)
    {
        int res = 0;
        while (n != 0)
        {
            n &= n - 1;
            ++res;
        }
        return res;
    }
public
    void normalSieve(int n, Set<Integer> st)
    {
        boolean[] is_prime = new boolean[n + 1];
        Arrays.fill(is_prime, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++)
        {
            if (is_prime[p])
            {
                for (int i = p * p; i <= n; i += p)
                {
                    is_prime[i] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (is_prime[i])
            {
                st.add(i);
            }
        }
    }
public
    int countPrimeSetBits(int left, int right)
    {

        Set<Integer> st = new HashSet<Integer>();
        ;
        normalSieve(32, st);
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            int cnt = cntBits(i);
            if (st.contains(cnt))
                ans++;
        }
        return ans;
    }
}