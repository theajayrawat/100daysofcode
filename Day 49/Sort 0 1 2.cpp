// Link:https://www.codingninjas.com/studio/problems/631055?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int mid=0;
   int low=0;
   int high=n-1;
   while(mid<=high){
      if(arr[mid]==0){
         swap(arr[mid],arr[low]);
         mid++;
         low++;
      }
      else if(arr[mid]==1)
         mid++;
      else{
         swap(arr[mid],arr[high]);
         high--;
      }
   }
}