// Link:https://leetcode.com/problems/search-in-rotated-sorted-array/
// Time Complexity: O(LogN)
// Space Complexity: O(1)

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[s] <= nums[mid])
            {
                if (nums[mid] >= target && target >= nums[s])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }

        return -1;
    }
};