// Link:https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/?envType=list&envId=rvf6y046
// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution {
    public static void rotate(int[][] matrix){
        int m = matrix.length;

         for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m/2; j++) {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][m-1-j];
                matrix[i][m-1-j]=temp;
            }
        }

    }
    
    public static boolean isEqual(int[][] m1 , int[][] m2){
        if(m1.length != m2.length) return false;
        if(m1[0].length != m2[0].length) return false;
        for(int row=0; row<m1.length; row++){
            for(int col = 0; col<m1[0].length; col++){
                if(m1[row][col] != m2[row][col]) return false;
            }
        }
        return true;
    }

    public boolean findRotation(int[][] mat, int[][] target) {
     
        for(int i=0; i<4; i++){
            if(isEqual(mat,target)) return true;
            rotate(mat);
        }
        return false;
    }  
    
}