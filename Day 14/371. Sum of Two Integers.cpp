// Webpage:https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = a & b;
            a = a^b;          
            b = (unsigned)carry << 1; 
        }
        
        return a;
    }
};