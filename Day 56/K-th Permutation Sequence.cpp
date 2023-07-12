// Link:https://www.codingninjas.com/studio/problems/1112626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2
// Time Complexity: O(N^2)    
// Space Complexity: O(N)

string kthPermutation(int n, int k)
{
    // Write your code here.
    vector<int> number;
    int block = 1;
    for (int i = 1; i < n; i++)
    {
        block *= i;
        number.push_back(i);
    }
    number.push_back(n);

    string ans;
    k--;
    while (true)
    {
        int index = k / block;
        ans += to_string(number[index]);
        number.erase(number.begin() + index);
        if (number.size() == 0)
            break;
        k %= block;
        block /= number.size();
    }
    return ans;
}