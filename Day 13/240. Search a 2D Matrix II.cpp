// Webpage:https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        if(matrix[0][0]>target || matrix[n-1][m-1]<target)
            return false;

        int i=0;
        int j=m-1;

        while(i<n && j>=0)
        {
            if(matrix[i][j]<target)
                i++;
            else if(matrix[i][j]>target)
                j--;
            else
                return true;
        }

        return false;
    }
};