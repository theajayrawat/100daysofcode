// Link:https://www.codingninjas.com/studio/problems/1089580?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
void solve(int i, vector<long long int>&temp){

  long long int ans=1;
  temp.push_back(ans);
  for(int j=1;j<i;j++){
    ans*=(i-j);
    ans/=j;
    temp.push_back(ans);
  }
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>ans;
  for(int i=1;i<=n;i++){
    vector<long long int>temp;
    solve(i, temp);
    ans.push_back(temp);
  }

  return ans;
}