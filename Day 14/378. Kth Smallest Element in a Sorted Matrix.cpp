// Webpage:https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> max_heap;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                max_heap.push(matrix[i][j]);
                if(max_heap.size() > k) {
                    max_heap.pop();
                }
            }
        }

        return max_heap.top();
    }
};
