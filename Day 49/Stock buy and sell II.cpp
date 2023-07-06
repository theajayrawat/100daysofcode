// Link:https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
// Time Complexity: O(N)
// Space Complexity: O(1)

lass Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int profit=0;

        for(int i=1;i<n;i++)
        {
            if(prices[i-1]<prices[i])
                profit+=prices[i]-prices[i-1];
        }

        return profit;
    }
};