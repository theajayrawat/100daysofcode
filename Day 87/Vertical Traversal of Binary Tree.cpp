// Link:https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // Your code here
        map<int, vector<int>> nodes;
        queue<pair<Node *, int>> q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;

            nodes[hd].push_back(frontNode->data);

            if (frontNode->left)
                q.push(make_pair(frontNode->left, hd - 1));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};