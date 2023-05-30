// Webpage:https://leetcode.com/problems/design-hashset/description/

class MyHashSet {
public:
    vector<list<int>>v;
    int size;

    int getHashValue(int key) {
        return key%size;
    }

    auto findValue(int key, int index) {
        return find(v[index].begin(), v[index].end(), key);
    }

    MyHashSet() {
        size=10000;
        v = vector<list<int>>(size, list<int>{});
    }
    
    void add(int key) {
        int index = getHashValue(key);

        auto itr=findValue(key,index);
        
        if(itr == v[index].end())
            v[index].push_back(key);

    }
    
    void remove(int key) {
        int index = getHashValue(key);

        auto itr=findValue(key,index);
        
        if(itr != v[index].end())
            v[index].erase(itr);

    }
    
    bool contains(int key) {
        int index = getHashValue(key);
        
        auto itr=findValue(key,index);

        return itr != v[index].end();
    }
};
