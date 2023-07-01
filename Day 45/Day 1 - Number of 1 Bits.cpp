// Link:https://practice.geeksforgeeks.org/problems/set-bits0143/1

// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
  public:
    int setBits(int N) {
        int count = 0;
        while (N) {
            N &= (N - 1);
            count++;
        }
        return count;
    }
};