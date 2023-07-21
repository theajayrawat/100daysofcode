// Link:https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
// Time Complexity:  O(N)
// Space Complexity: O(1)

class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        // Your code here
        vector<int> freq(26, 0);
        int n = S.size();

        for (int i = 0; i < n; i++)
        {
            freq[S[i] - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (freq[S[i] - 'a'] == 1)
                return S[i];
        }

        return '$';
    }
};