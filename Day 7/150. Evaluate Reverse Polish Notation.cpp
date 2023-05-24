// Webpage:https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();

                int eval=0;
                if(tokens[i]=="+")
                    eval=a+b;
                else if(tokens[i]=="-")
                    eval=b-a;
                else if(tokens[i]=="*")
                    eval=a*b;
                else 
                    eval=b/a;

               s.push(to_string(eval));
            }
            else s.push(tokens[i]);
        }
        return stoi(s.top());
    }
};