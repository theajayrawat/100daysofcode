// Webpage:https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        string final_ans; 
        if((numerator<0&&denominator>0) ||(numerator>0&&denominator<0))
            ans.append("-");

        long  d= abs(denominator);
        long  n= abs(numerator);
        
        ans = ans+to_string((long)(n/d));
        unordered_map<long,int> m;
        long  remainder = n%d;
        if(remainder!=0)
        {
            ans.append(".");
            while(ans.size()<=1e4)
            {
                if(remainder ==0 ||m.find(remainder)!=m.end())
                    break;
    
                m[remainder] = ans.size();
                long  t= (remainder*10)/d;
                ans.append(to_string(t));
                remainder = (remainder*10)%d;
            }
            if(m.find(remainder)!=m.end())
            {
                cout<<ans<<m[remainder];
                final_ans = ans.substr(0,m[remainder]) + "("+ ans.substr(m[remainder])+")";
            }
            else
            {
                 final_ans = ans;
            }      
        }
        else
        {
            final_ans = ans;
        }

        return final_ans;
    }
};