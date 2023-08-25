// Link:https://practice.geeksforgeeks.org/problems/multiply-two-strings/1
// Space Complexity: O(n1 * n2)
// Time Complexity: O(n1 + n2)

class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2)
    {
        int sign = 1;

        if (num1[0] == '-')
        {
            sign *= -1;
            num1 = num1.substr(1);
        }

        if (num2[0] == '-')
        {
            sign *= -1;
            num2 = num2.substr(1);
        }

        int n1 = num1.size(), n2 = num2.size();
        string res(n1 + n2, '0');

        for (int i = n2 - 1; i >= 0; i--)
        {
            int d2 = num2[i] - '0';
            int carry = 0;
            for (int j = n1 - 1; j >= 0; j--)
            {
                int d1 = num1[j] - '0';
                int prod = d1 * d2 + carry + (res[i + j + 1] - '0');
                carry = prod / 10;
                res[i + j + 1] = prod % 10 + '0';
            }
            res[i] += carry;
        }

        string result = "";
        bool leading_zeros = true;

        for (char c : res)
        {
            if (leading_zeros && c == '0')
                continue;
            leading_zeros = false;
            result += c;
        }

        if (sign == -1)
            result = '-' + result;
        return result.empty() ? "0" : result;
    }
};