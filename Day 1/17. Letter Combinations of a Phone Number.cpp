// Website:https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void combinations(vector<string>&ans, string digits, int i, string curr)
    {
        if(digits.size()==i)
        {
            ans.push_back(curr);
            return;
        }

        int index=digits[i]-'0';
        string str=v[index];

        for(int j=0;j<str.size();j++)
        {
            combinations(ans,digits,i+1,curr+str[j]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;

        if(digits.size()==0)
            return ans;

        combinations(ans,digits,0,"");
        return ans;
    }
};