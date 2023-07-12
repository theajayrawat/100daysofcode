// Link:https://www.codingninjas.com/studio/problems/759331?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O(k * 2^n)     "k" is average length of every subset 
// Space Complexity: O(2^n * k) 


void solve(int i, int k, vector<int> &num, vector<vector<int>> &ans,
           vector<int> temp) {
  if (i == num.size()) {
    if (k == 0 && temp.size()!=0)
      ans.push_back(temp);
    return;
  }

  
  solve(i + 1, k, num, ans, temp);
  temp.push_back(num[i]);
  solve(i + 1, k - num[i], num, ans, temp);
 
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
  vector<vector<int>> ans;
  vector<int> temp;
  solve(0, k, arr, ans, temp);
  return ans;
}