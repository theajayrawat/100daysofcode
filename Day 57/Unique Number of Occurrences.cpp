// Link:https://practice.geeksforgeeks.org/problems/unique-frequencies-of-not/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
       unordered_map<int,int>mp,np;
       for(int i=0;i<n;i++)mp[arr[i]]++;
       
       for(auto &i:mp){
           if(np.find(i.second)!=np.end())
            return false;
           np[i.second]++;
       }
       
       return true;
    }
}