// Link:https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
        }

        int mask = 1;
        while (!(mask & x))
        {
            mask <<= 1;
        }

        int val1 = 0, val2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & mask)
            {
                val1 ^= nums[i];
            }
            else
            {
                val2 ^= nums[i];
            }
        }

        if (val1 < val2)
            return {val1, val2};

        return {val2, val1};
    }
};