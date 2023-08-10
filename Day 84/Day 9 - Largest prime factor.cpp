// Link:https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1
// Time Complexity: O(sqrt(N))
// Space Complexity: O(1)

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        int num = 2;
        while ((num * num) <=N)
        if (N % num == 0) 
            N /= num; 
        else
            num++; 
        return N;
        
    }
};