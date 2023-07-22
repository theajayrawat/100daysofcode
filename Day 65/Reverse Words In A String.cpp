// Link:https://www.codingninjas.com/studio/problems/696444?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O(N)
// Sapce Complexity: O(N)

string reverseString(string &str)
{

    string ans;

    int start = str.length() - 1;

    while (start >= 0)
    {

        // Skip multiple spaces.
        if (str[start] == ' ')
        {
            start--;
        }
        else
        {

            // Add space between words.
            if (ans.length() > 0)
            {
                ans.push_back(' ');
            }

            int j = start;

            while (j >= 0 && str[j] != ' ')
            {
                j--;
            }

            // Add current word to ans.
            ans.append(str.substr(j + 1, start - j));
            start = j;
        }
    }

    return ans;
}