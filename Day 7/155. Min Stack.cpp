// Webpage:https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    vector<int>v;
    int size;
    int mini;
    MinStack() {
        size=0;
        mini=INT_MAX;
    }
    
    void push(int val) {
        v.push_back(val);
        size++;
        if(mini>val)
            mini=val;
    }
    
    void pop() {
        size--;
        v.pop_back();
        if(mini==v[size]){
            mini=*min_element(v.begin(),v.begin()+size);
        }
        if(size==0)
            mini=INT_MAX;
    }
    
    int top() {
        return v[size-1];
    }
    
    int getMin() {
        return mini;
    }
};