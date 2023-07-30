// Link:https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/blems/find-the-index-of-the-first-occurrence-in-a-string/
// Time Complexity: O(M+N)
// Space Complexity: O(M)


class Solution {
public:
    vector<int> kmp(string s, int n){
        vector<int>v(n,0);

        for(int i=1;i<n;i++){
            int j=v[i-1];
            while(j>0 && s[j]!=s[i]){
                j=v[j-1];
            }

            if(s[j]==s[i])
                j++;

            v[i]=j;
        }

        return v;

    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        vector<int>prefix=kmp(needle,m);
        int j=0,i=0;

        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0)
                    j=prefix[j-1];
                else
                    i++;
            }

            if(j==m)
                return i-m;
        }

        return -1;
    }
};
