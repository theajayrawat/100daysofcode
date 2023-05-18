// Website:https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string str=countAndSay(n-1);
        string ans;
        int i=0;
        while(i<str.size())
        {
            int count=1;
            while(i+1<str.size() && str[i]==str[i+1])
            {
                count++;
                i++;
            }
                
            ans+=to_string(count);
            ans+=str[i];
            i++;
        }

        return ans;
    }
};