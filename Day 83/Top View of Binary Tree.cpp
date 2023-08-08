// Link:https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        map<int, int> v;

        vector<int> a;
        if (!root)
            return a;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (q.size())
        {
            Node *t = q.front().first;
            int vh = q.front().second;
            q.pop();

            if (v[vh] == 0)
                v[vh] = t->data;

            if (t->left)
                q.push({t->left, vh - 1});
            if (t->right)
                q.push({t->right, vh + 1});
        }

        for (auto x : v)
            a.push_back(x.second);
        return a;
    }
};