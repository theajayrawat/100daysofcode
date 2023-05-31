// Webpage:https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    static bool cmp(pair<int, int>& a,pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<pair<int, int>> sorted(map<int,int>mp)
    {
 
        vector<pair<int, int>> A;
   
        for (auto& it : mp) {
            A.push_back(it);
        }
 
        sort(A.begin(), A.end(), cmp);

        return A;

    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> A=sorted(mp);

        vector<int>ans;
        for (auto& it : A) {
            if(k==0)
                break;
            ans.push_back(it.first);
            k--;
        }

        return ans;
        
    }
};