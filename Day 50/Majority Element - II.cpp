// Link:https://www.codingninjas.com/studio/problems/893027?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr) {
  // Write your code here.
  vector<int> ans;
  int n = arr.size();
  int cnt1 = 0;
  int val1 = INT_MIN;
  int cnt2 = 0;
  int val2 = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (cnt1 == 0 && val2 != arr[i]) {
      cnt1 = 1;
      val1 = arr[i];
    } else if (cnt2 == 0 && val1 != arr[i]) {
      cnt2 = 1;
      val2 = arr[i];
    } else if (arr[i] == val1)
      cnt1++;
    else if (arr[i] == val2)
      cnt2++;
    else {
      cnt1--, cnt2--;
    }
  }

  cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == val1)
      cnt1++;
    if (arr[i] == val2)
      cnt2++;
  }

  if (cnt1 > n / 3)
    ans.push_back(val1);
  if (cnt2 > n / 3)
    ans.push_back(val2);

  return ans;
}