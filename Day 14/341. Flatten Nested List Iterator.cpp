// Webpage:https://leetcode.com/problems/flatten-nested-list-iterator/

class NestedIterator {
public:
    stack<NestedInteger> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        for(int i=nestedList.size()-1;i>=0;i--){
            s.push(nestedList[i]);
        }
    }
    
    int next() {
        int ans=s.top().getInteger();
        s.pop();
        return ans;
    }
    
    bool hasNext() {
        while(!s.empty()){
            NestedInteger curr=s.top();
            if(curr.isInteger()){
                return true;
            }
            s.pop();
            vector<NestedInteger>& elements=curr.getList();
            for(int i=elements.size()-1;i>=0;i--){
                s.push(elements[i]);
            }
            
        }
        return false;
    }
};