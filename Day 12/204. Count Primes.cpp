// Webpage:https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) 
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int countPrimes(int n) {
        if(n <= 2) 
            return 0;

        vector<int>isPrime(n,true);

        for(int i = 2; i*i < n; i++)
        {
            if(isPrime[i] ==true) 
            {
                for(int j = i*i; j < n; j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int ans=0;
        for(int i=2;i<isPrime.size();i++)
        {
            if(isPrime[i] == true) 
            {
                ans++;
            }
                
        }

        return ans;
    }
};