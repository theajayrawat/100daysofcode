// Link:https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// Time Complexity: O(32 * R * log ( C ))
// Space Complexity: O(1)

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here    
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            if (matrix[i][0] < min)
                min = matrix[i][0];
     
            if (matrix[i][C-1] > max)
                max = matrix[i][C-1];
        }
     
        int desired = (R * C + 1) / 2;
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int place = 0;
            for (int i = 0; i < R; ++i)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
};

