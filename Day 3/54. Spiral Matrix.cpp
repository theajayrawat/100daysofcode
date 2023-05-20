// Webpage:https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int t=n*m;
        vector<int>v;
        int start_col=0;
        int start_row=0;
        int end_col=m-1;
        int end_row=n-1;

        while(v.size()<t)
        {
            for(int i=start_col;i<=end_col;i++)
                v.push_back(matrix[start_row][i]);

            start_row++;

            for(int i=start_row;i<=end_row;i++)
                v.push_back(matrix[i][end_col]);

            end_col--;
            
            for(int i=end_col;i>=start_col && start_row<=end_row;i--)
                v.push_back(matrix[end_row][i]);

            end_row--;

            for(int i=end_row;i>=start_row && start_col<=end_col;i--)
                v.push_back(matrix[i][start_col]);

            start_col++;
        }

        return v;
    }
};