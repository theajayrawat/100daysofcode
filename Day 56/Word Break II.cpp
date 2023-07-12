// Link:https://www.codingninjas.com/studio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O((N^2)*K) "K" average length of list
// Space Complexity: O(K*x)     "x" total list

#include <bits/stdc++.h>
void help(vector<string> &v, string &s, vector<string> temp, int i, unordered_set<string> &se)
{
    if (i == s.size())
    {
        string str = "";
        for (auto it : temp)
        {
            str += it + " ";
        }
        str.pop_back();
        v.push_back(str);
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        string st = s.substr(i, j - i + 1);
        if (se.find(st) != se.end())
        {
            temp.push_back(st);
            help(v, s, temp, j + 1, se);
            temp.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string> se;
    for (int i = 0; i < dictionary.size(); i++)
        se.insert(dictionary[i]);

    vector<string> v;
    if (s.empty())
        return v;
    vector<string> temp;
    help(v, s, temp, 0, se);
    return v;
}