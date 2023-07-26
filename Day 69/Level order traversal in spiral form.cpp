// Link:https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
// Time Complexity: O(N)
// Space Complexity: O(H)

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    // Your code here
    vector<int> res;
    if (!root)
        return {};
    stack<Node *> even;
    stack<Node *> odd;
    odd.push(root);
    while (!even.empty() || !odd.empty())
    {
        if (!even.empty())
        {
            while (!even.empty())
            {
                Node *temp = even.top();
                even.pop();
                if (temp->left)
                    odd.push(temp->left);
                if (temp->right)
                    odd.push(temp->right);
                res.push_back(temp->data);
            }
        }
        else if (!odd.empty())
        {
            while (!odd.empty())
            {
                Node *temp = odd.top();
                odd.pop();
                if (temp->right)
                    even.push(temp->right);
                if (temp->left)
                    even.push(temp->left);
                res.push_back(temp->data);
            }
        }
    }
    return res;
}