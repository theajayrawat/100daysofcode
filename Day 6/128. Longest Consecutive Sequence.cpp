// Webpage:https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    vector<int> parent;
    vector<int>size;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent]+=size[y_parent];

        } 
        else {
            parent[x_parent] = y_parent;
            size[y_parent]+=size[x_parent];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) 
            return 0;

        parent.resize(n);
        size.resize(n,1);
        
        for(int i = 0; i<n; i++)
            parent[i] = i;

        unordered_set<int> set;
        unordered_map<int, int> numIDs;
        for (int i = 0; i < n; i ++) {
            numIDs[nums[i]] = i;
            set.insert(nums[i]);
        }

        for (int num : set) {
            if (set.count(num - 1)) // it is not the first value in a consecutive sequence
                continue;

            // num could be the first value in a consecutive sequence
            int curNum = num;
            while (set.count(curNum+1)) {
                Union(numIDs[curNum], numIDs[curNum+1]);
                curNum += 1;
            }
        }

        return *max_element(size.begin(), size.end());
    }
};