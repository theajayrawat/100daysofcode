// Webpage:https://leetcode.com/problems/group-anagrams/

class Solution {
public:
   
    unordered_map<char,int> mapString(string s)
    {
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;    

        return mp;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<unordered_map<char,int>>freq;

        for(int i=0;i<strs.size();i++)
        {
            freq.push_back(mapString(strs[i]));
        }

        vector<bool>checkAvailable(strs.size(),true);  
        for(int i=0;i<strs.size();i++)
        {
            vector<string>temp;
            if(!checkAvailable[i])
                continue;
            temp.push_back(strs[i]);
            checkAvailable[i]=false;

            for(int j=i+1;j<strs.size();j++)
            {
                if(checkAvailable[j] && freq[i]==freq[j])
                {
                    temp.push_back(strs[j]);
                    checkAvailable[j]=false;
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};