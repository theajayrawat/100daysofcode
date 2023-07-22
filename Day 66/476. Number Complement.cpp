// Link:https://leetcode.com/problems/number-complement/
// Time Complexity: O(1)
// Sapce Complexity: O(1)

class Solution {
    public int countBits(int n){
        int count=0;
        while(n>0)
        {
            count++;
            n=n>>1;
        }
        return count;
    }
    public int findComplement(int num) {

        int cnt=countBits(num);
        for(int i=0;i<cnt;i++){
            num=num^(1<<i);
        }

        return num;
    }
}