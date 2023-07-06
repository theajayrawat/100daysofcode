// Link:https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int slow=arr[0];
	int fast=arr[0];
	slow=arr[slow];
	fast=arr[arr[fast]];
	while(slow!=fast){
		slow=arr[slow];
		fast=arr[arr[fast]];
	}

	fast=arr[0];
	while(slow!=fast){
		slow=arr[slow];
		fast=arr[fast];
	}

	return slow;
}
