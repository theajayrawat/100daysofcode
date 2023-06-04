// Webpage:https://leetcode.com/problems/sum-of-matrix-after-queries/

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool>checkRow(n,false);
        vector<bool>checkCol(n,false);
        int rowRemain=n;
        int colRemain=n;
        long sum=0;

        for(int i=queries.size()-1;i>=0;i--)
        {
            int type=queries[i][0];
            int index=queries[i][1];
            int val=queries[i][2];

            if(type==0 && !checkRow[index])
            {
                sum += colRemain * val;    
                checkRow[index] = true; 
                rowRemain--;           
            }
            else if(type==1 && !checkCol[index])
            {
                sum += rowRemain * val;    
                checkCol[index] = true; 
                colRemain--;  
            }
        }

        return sum;
    }
};