// Link:https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        for(int i=l;i<=r;i++){    
            int m=1<<(i-1);
            if(y&m){              
                x|=m;        
            }
        }
        return x;
  
    }
};